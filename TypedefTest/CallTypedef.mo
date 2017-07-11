model CallTypedef
	Real z(start=0); 
	function test_typedef
		input Real x(start=0);
		input Real y(start=0);
		output Real z(start=0);
		external "C"  annotation(Library = "test_typedef", LibraryDirectory = "modelica://CallTypedef");
	end test_typedef;

equation
	z = test_typedef(time,time);
	annotation(uses(Modelica(version = "3.2.1")));
end CallTypedef;