function SimpleC
  input Real iDouble;
  input String directPath;
  output Real returnDouble=iDouble;

  external "C" store(iDouble)
      annotation (IncludeDirectory=directPath, Include="#include \"storeInput.c\"");

end SimpleC;
