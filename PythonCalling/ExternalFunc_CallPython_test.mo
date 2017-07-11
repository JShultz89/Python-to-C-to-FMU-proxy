model ExternalFunc_CallPython_test
  Real z(start = 0);

  function DLLCallPython_test
    input Real x(start = 0);
    input Real y(start = 0);
    output Real z(start = 0);
  
    external "C"  annotation(Library = "DLLCallPython_test", LibraryDirectory = "modelica://ExternalFunc_CallPython_test");
  end DLLCallPython_test;
equation
  z = DLLCallPython_test(time, time);
  annotation(uses(Modelica(version = "3.2.1")));
end ExternalFunc_CallPython_test;