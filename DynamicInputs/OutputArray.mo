model OutputArray
  Real r[4] = {time, 1, 1, 2} "Declare array of 4 Real or double values, can be changed to an input for E+"; 
  record MultiVal "equivalent of struct MultiVal in C, maps the 5 outputs from C to each of the items in the record. Add or subtract more values as needed."
  	Real a,b,c,d,e; 
  end MultiVal;
  MultiVal z "Declare Multival type to variable with the name z"; 

  function outputTest "External Function, references the C code that calls the Python code"
    input Real x[:] "Input: array of doubles";
    output MultiVal m "Output: MultiVal struct";
  
    external "C"  annotation(Library = "outputTest", LibraryDirectory = "modelica://OutputArray");
  end outputTest;
equation
  z = outputTest(r) "Call External Function, input array r, storing result in struct MultiVal z";
  annotation(uses(Modelica(version = "3.2.1")));
end OutputArray;