model AddMO "Description"
  input Real FirstInput(start=0);
  input Real SecondInput(start=0);
  output Real FMUOutput;
equation
	FMUOutput = FirstInput + SecondInput;  
end AddMO;