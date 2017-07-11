/**This model works with the external C function storeData which takes input, stores it
in an array, and returns what is stored in the array to confirm that it has been stored 
properly.  
**/

model StoreData_Trial1
	function storeData 
		input Real x;
		output Real y;
		external "C"  annotation(Library = "storeData", LibraryDirectory = "modelica://StoreData_Trial1");
	end storeData;

	Real x(start = 1.0, fixed = true);
equation
	der(x) = -storeData(x);
end StoreData_Trial1;