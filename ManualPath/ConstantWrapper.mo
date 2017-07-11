within ;
model ConstantWrapper "Test giving one value to the SimpleC program"

  SimpleCWrapper simpleCWrapper1
    annotation(Placement(visible = true, transformation(origin = {38,10}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant const(k=25.0)
    annotation (Placement(transformation(extent={{-28,0},{-8,20}})));
equation
  connect(const.y, simpleCWrapper1.SimpleDouble)
    annotation (Line(points={{-7,10},{28,10},{28,10.2}}, color={0,0,127}));
annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)),
    uses(Modelica(version="3.2.2")));
end ConstantWrapper;
