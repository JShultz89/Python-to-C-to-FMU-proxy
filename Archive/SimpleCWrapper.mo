model SimpleCWrapper "The purpose of this model is to wrapp the SimpleC modelica function. I do not believe functions can be directly exported as FMUs -JS"
  Modelica.Blocks.Interfaces.RealInput SimpleDouble annotation(Placement(visible = true, transformation(origin = {-100, 0}, extent = {{-20, -20}, {20, 20}}, rotation = 0), iconTransformation(origin = {-100, 2}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));
  Real returnedDouble;
protected
  constant String direct = Modelica.Utilities.Files.loadResource("C:\\Users\\justin.shultz\\Dropbox\\FMU\\Passing_Data_Testing\\");
equation
  returnedDouble=SimpleC(SimpleDouble, direct);
annotation(uses(Modelica(version="3.2.2")));
end SimpleCWrapper;
