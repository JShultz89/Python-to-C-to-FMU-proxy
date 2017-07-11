model SineWrapper
  SimpleCWrapper simpleCWrapper1 annotation(Placement(visible = true, transformation(origin = {38,10}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Sine sine1(freqHz=1) annotation(Placement(visible = true, transformation(origin = {-24, 10}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(sine1.y, simpleCWrapper1.SimpleDouble) annotation(Line(points = {{-12, 10}, {28, 10}, {28, 10}, {28, 10}}, color = {0, 0, 127}));
  annotation(uses(Modelica(version = "3.2.1")));
end SineWrapper;