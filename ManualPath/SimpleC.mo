function SimpleC
  input Real iDouble;
  output Real returnDouble=iDouble;

  external "C" store(iDouble)
      annotation (IncludeDirectory="C:\\Users\\justin.shultz\\Dropbox\\FMU\\Passing_Data_Testing", Include="#include \"storeInput.c\"");

end SimpleC;
