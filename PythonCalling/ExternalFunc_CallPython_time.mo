model ExternalFunc_CallPython_time
  Real z(start=0);

  function DLLCallPython
    input Real x(start=0);
    input Real y(start=0);
    output Real z(start=0);
    external "C"  annotation(Library = "DLLCallPython", LibraryDirectory = "modelica://ExternalFunc_CallPython_time");
  end DLLCallPython;
equation
  z = DLLCallPython(time,time);
  annotation(uses(Modelica(version = "3.2.1")));
end ExternalFunc_CallPython_time;