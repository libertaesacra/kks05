#include "kks05App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
kks05App::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

kks05App::kks05App(InputParameters parameters) : MooseApp(parameters)
{
  kks05App::registerAll(_factory, _action_factory, _syntax);
}

kks05App::~kks05App() {}

void
kks05App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"kks05App"});
  Registry::registerActionsTo(af, {"kks05App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
kks05App::registerApps()
{
  registerApp(kks05App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
kks05App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kks05App::registerAll(f, af, s);
}
extern "C" void
kks05App__registerApps()
{
  kks05App::registerApps();
}
