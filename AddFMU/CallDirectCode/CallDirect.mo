model CallDirect "Description"
  input Real FirstInput(start=0);
  input Real SecondInput(start=0);
  output Real FMUOutput(start=0);

  function CAdd
    input Real x;
    input Real y;
    output Real z;
    external "C" annotation(Include="
    double CAdd(double x, double y){
    double answer;
    answer = x + y;
    return answer;
    }
    ");
  end CAdd;
equation
  FMUOutput = CAdd(FirstInput,SecondInput);
  annotation(uses(Modelica(version = "3.2.1")));
end CallDirect;
