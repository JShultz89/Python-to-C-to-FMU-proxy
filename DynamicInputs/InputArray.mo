model InputArray
  Real z(start = 0);
  Real r[3] = {time, 1, 1};

  function arrayTest
    input Real x[:];
    output Real z(start = 0);
  
    external "C"  annotation(Library = "arrayTest", LibraryDirectory = "modelica://InputArray");
  end arrayTest;
equation
  z = arrayTest(r);
  annotation(uses(Modelica(version = "3.2.1")));
end InputArray;