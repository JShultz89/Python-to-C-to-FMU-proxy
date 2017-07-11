model ExternalFunc_CallPython
  Modelica.Blocks.Interfaces.RealInput u
    annotation (Placement(transformation(extent={{-120,32},{-80,72}})));
  Modelica.Blocks.Interfaces.RealInput u1
    annotation (Placement(transformation(extent={{-120,-38},{-80,2}})));
 output Real z;

function DLLCallPython
  input Real x;
  input Real y;
  output Real z;
  external "C"  annotation(Library = "DLLCallPython", LibraryDirectory = "modelica://ExternalFunc_CallPython");
end DLLCallPython;

equation
 z =  DLLCallPython(u,u1);
  annotation (uses(Modelica(version="3.2.1")));
end ExternalFunc_CallPython;
