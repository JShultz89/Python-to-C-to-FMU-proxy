model CallExternalC
	Modelica.Blocks.Sources.Constant const(k=25.0)
    annotation (Placement(transformation(extent={{-28,0},{-8,20}})));
algorithm
  CStoreSlash(const.y);
end CallExternalC;