model ExternalLibraries

  function ExternalFunc1
    input Real x;
    output Real y;
  external y=ExternalFunc1_ext(x) annotation(Library="ExternalFunc1.o", LibraryDirectory="modelica://ExternalLibraries", Include="#include \"ExternalFunc1.h\"");
  end ExternalFunc1;

  function ExternalFunc2
    input Real x;
    output Real y;
  external "C" annotation(Library="ExternalFunc2", LibraryDirectory="modelica://ExternalLibraries");
  end ExternalFunc2;

  Real x(start=1.0, fixed=true), y(start=2.0, fixed=true);
equation
  der(x)=-ExternalFunc1(x);
  der(y)=-ExternalFunc2(y);
end ExternalLibraries;