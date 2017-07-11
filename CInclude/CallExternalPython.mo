model CallExternalPython
algorithm
  pyRunString("
    print 'Python says: simulation time'," + String(time) + "
    ");
end CallExternalPython;