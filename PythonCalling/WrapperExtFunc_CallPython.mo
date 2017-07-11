within ;
model WrapperExtFunc_CallPython

  ExternalFunc_CallPython externalFunc_CallPython
    annotation (Placement(transformation(extent={{-8,-14},{12,8}})));
  Modelica.Blocks.Sources.Clock clock
    annotation (Placement(transformation(extent={{-66,4},{-46,24}})));
  Modelica.Blocks.Sources.Constant const(k=5)
    annotation (Placement(transformation(extent={{-66,-32},{-46,-12}})));
equation

  connect(clock.y, externalFunc_CallPython.u) annotation (Line(points={{-45,14},
          {-26,14},{-26,2.72},{-8,2.72}}, color={0,0,127}));
  connect(const.y, externalFunc_CallPython.u1) annotation (Line(points={{-45,
          -22},{-26,-22},{-26,-4.98},{-8,-4.98}}, color={0,0,127}));
  annotation (
    Icon(coordinateSystem(preserveAspectRatio=false)),
    Diagram(coordinateSystem(preserveAspectRatio=false)),
    uses(Modelica(version="3.2.1")));
end WrapperExtFunc_CallPython;
