//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "kks05TestApp.h"
#include "kks05App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
kks05TestApp::validParams()
{
  InputParameters params = kks05App::validParams();
  return params;
}

kks05TestApp::kks05TestApp(InputParameters parameters) : MooseApp(parameters)
{
  kks05TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

kks05TestApp::~kks05TestApp() {}

void
kks05TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  kks05App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"kks05TestApp"});
    Registry::registerActionsTo(af, {"kks05TestApp"});
  }
}

void
kks05TestApp::registerApps()
{
  registerApp(kks05App);
  registerApp(kks05TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
kks05TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kks05TestApp::registerAll(f, af, s);
}
extern "C" void
kks05TestApp__registerApps()
{
  kks05TestApp::registerApps();
}
