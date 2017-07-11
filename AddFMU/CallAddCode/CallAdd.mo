model CallAdd
	input Real FirstInput(start=0);
	input Real SecondInput(start=0);
	output Real FMUOutput(start=0); 
	function CAdd
		input Real x(start=0);
		input Real y(start=0);
		output Real z(start=0);
		external "C"  annotation(Library = "CAdd", LibraryDirectory = "modelica://CallAdd");
	end CAdd;

equation
	FMUOutput = CAdd(FirstInput,SecondInput);
	annotation(uses(Modelica(version = "3.2.1")));
end CallAdd;