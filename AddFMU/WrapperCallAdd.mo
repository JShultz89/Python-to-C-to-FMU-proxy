model WrapperCallAdd
  //Modelica.Blocks.Sources.Constant const(k = 5) annotation(Placement(visible = true, transformation(origin = {-52, 38}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  //Modelica.Blocks.Sources.Sine sine1 annotation(Placement(visible = true, transformation(origin = {-52, 78}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  //CallAdd callAdd1 annotation(Placement(visible = true, transformation(origin = {6, 56}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Sine sine2 annotation(Placement(visible = true, transformation(origin = {-50, -6}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant const1(k = 5) annotation(Placement(visible = true, transformation(origin = {-50, -46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  CallDirect callDirect1 annotation(Placement(visible = true, transformation(origin = {8, -26}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  //connect(callAdd1.SecondInput, const.y) annotation(Line);
  //connect(callAdd1.FirstInput, sine1.y) annotation(Line);
  connect(callDirect1.SecondInput, const1.y) annotation(Line);
  connect(callDirect1.FirstInput, sine2.y) annotation(Line);
  annotation(uses(Modelica(version = "3.2.1")), experiment(StartTime = 0, StopTime = 20, Tolerance = 1e-06, Interval = 0.02));
end WrapperCallAdd;