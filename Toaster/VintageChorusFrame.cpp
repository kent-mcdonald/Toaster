/*  This file is part of Toaster, the editor and remote control for Kemper profiling amplifier.
*
*   Copyright (C) 2016  Thomas Langer
*
*   Toaster is free software: you can redistribute it and/or modify it under the terms of the
*   GNU General Public License as published by the Free Software Foundation, either version 3
*   of the License, or (at your option) any later version.
*
*   Toaster is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
*   even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*   See the GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along with Toaster.
*   If not, see <http://www.gnu.org/licenses/>.
*/
#include "VintageChorusFrame.h"
#include "ui_VintageChorusFrame.h"
#include "Stomp.h"

VintageChorusFrame::VintageChorusFrame(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::VintageChorusFrame)
  , mpStomp(nullptr)
  , mFXType(None)
{
  ui->setupUi(this);
  ui->crossoverDial->setLookUpTable(LookUpTables::getFrequencyValues());
}

VintageChorusFrame::~VintageChorusFrame()
{
  delete ui;
}

void VintageChorusFrame::activate(QObject& stomp)
{
  mpStomp = qobject_cast<Stomp*>(&stomp);

  if(mpStomp != nullptr)
  {
    connect(mpStomp, SIGNAL(modulationRateReceived(double)), this, SLOT(onRate(double)));
    connect(mpStomp, SIGNAL(modulationDepthReceived(double)), this, SLOT(onDepth(double)));
    connect(mpStomp, SIGNAL(modulationCrossoverReceived(int)), this, SLOT(onCrossover(int)));
    connect(mpStomp, SIGNAL(mixReceived(double)), this, SLOT(onMix(double)));
    connect(mpStomp, SIGNAL(volumeReceived(double)), this, SLOT(onVolume(double)));
    connect(mpStomp, SIGNAL(duckingReceived(double)), this, SLOT(onDucking(double)));

    mpStomp->requestModulationRate();
    mpStomp->requestModulationDepth();
    mpStomp->requestModulationCrossover();
    mpStomp->requestMix();
    mpStomp->requestVolume();
    mpStomp->requestDucking();

    ui->lcdDisplay->setStompInstance(LookUpTables::stompInstanceName(mpStomp->getInstance()));
    ui->lcdDisplay->setStompName(LookUpTables::stompFXName(mpStomp->getFXType()));
  }
}

void VintageChorusFrame::deactivate()
{
  if(mpStomp != nullptr)
  {
    disconnect(mpStomp, SIGNAL(modulationRateReceived(double)), this, SLOT(onRate(double)));
    disconnect(mpStomp, SIGNAL(modulationDepthReceived(double)), this, SLOT(onDepth(double)));
    disconnect(mpStomp, SIGNAL(modulationCrossoverReceived(int)), this, SLOT(onCrossover(int)));
    disconnect(mpStomp, SIGNAL(mixReceived(double)), this, SLOT(onMix(double)));
    disconnect(mpStomp, SIGNAL(volumeReceived(double)), this, SLOT(onVolume(double)));
    disconnect(mpStomp, SIGNAL(duckingReceived(double)), this, SLOT(onDucking(double)));
  }
  mpStomp = nullptr;
}

QToasterLCD::Page VintageChorusFrame::getMaxDisplayPage()
{
  return ui->lcdDisplay->maxPage();
}

QToasterLCD::Page VintageChorusFrame::getCurrentDisplayPage()
{
  return ui->lcdDisplay->currentPage();
}

void VintageChorusFrame::setCurrentDisplayPage(QToasterLCD::Page page)
{
  if(page <= ui->lcdDisplay->maxPage())
  {
    ui->lcdDisplay->setCurrentPage(page);
  }
}

void VintageChorusFrame::displayStompType(StompInstance stompInstance, FXType fxType)
{
  ui->lcdDisplay->setStompFXType(stompInstance, fxType);
}

void VintageChorusFrame::displayStompEnabled(StompInstance stompInstance, bool enabled)
{
  ui->lcdDisplay->setStompEnabled(stompInstance, enabled);
}

void VintageChorusFrame::displayDelayEnabled(bool enabled)
{
  ui->lcdDisplay->setDelayEnabled(enabled);
}

void VintageChorusFrame::displayReverbEnabled(bool enabled)
{
  ui->lcdDisplay->setReverbEnabled(enabled);
}

void VintageChorusFrame::displayAmpName(const QString&  ampName)
{
  ui->lcdDisplay->setAmpName(ampName);
}

void VintageChorusFrame::on_rateDial_valueChanged(double value)
{
  if(mpStomp != nullptr)
    mpStomp->applyModulationRate(value);
}

void VintageChorusFrame::on_depthDial_valueChanged(double value)
{
  if(mpStomp != nullptr)
    mpStomp->applyModulationDepth(value);
}

void VintageChorusFrame::on_crossoverDial_valueChanged(int value)
{
  if(mpStomp != nullptr)
    mpStomp->applyModulationCrossover(value);
}

void VintageChorusFrame::on_mixDial_valueChanged(double value)
{
  if(mpStomp != nullptr)
    mpStomp->applyMix(value);
}

void VintageChorusFrame::on_volumeDial_valueChanged(double value)
{
  if(mpStomp != nullptr)
    mpStomp->applyVolume(value);
}

void VintageChorusFrame::on_duckingDial_valueChanged(double value)
{
  if(mpStomp != nullptr)
    mpStomp->applyDucking(value);
}

void VintageChorusFrame::onRate(double value)
{
  ui->rateDial->setValue(value);
  update();
}

void VintageChorusFrame::onDepth(double value)
{
  ui->depthDial->setValue(value);
  update();
}

void VintageChorusFrame::onCrossover(int value)
{
  ui->crossoverDial->setValue(value);
  update();
}

void VintageChorusFrame::onMix(double value)
{
  ui->mixDial->setValue(value);
  update();
}

void VintageChorusFrame::onVolume(double value)
{
  ui->volumeDial->setValue(value);
  update();
}

void VintageChorusFrame::onDucking(double value)
{
  ui->duckingDial->setValue(value);
  update();
}
