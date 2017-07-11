model TestString
  //extends Modelica.Utilities.Internal.PartialModelicaServices.ExternalReferences.PartialLoadResource;
  //extends ModelicaServices.ExternalReferences.loadResource;
  input Real iDouble;

  String direct = Modelica.Utilities.Files.loadResource("C:\\Users\\justin.shultz\\Dropbox\\FMU\\Passing_Data_Testing\\");
end TestString;
