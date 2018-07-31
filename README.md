# CST276SRS03
Shape Composite Factory  

This SRS is weighted at 2x.  

Project Name(s):  

    - GoFFactoryMethod  
    - GoFComposite  
    - CompositeFactory  

Purposes:  

    - Learn to implement the canonical GoF Factory Method Pattern.  
    - Learn to implement the canonical GoF Composite Pattern.  
    - Learn to implement the Factory Method Pattern.  
    - Learn to implement the Composite Pattern.  
    - Learn how to design a solution using interfaces.  
    - Learn how to expect, prepare, and respond to evolving specifications.  
    - Learn how to plumb for read, write, create, and display drawing operations.  

Motivation Scenario:  
    
You've been asked to add rudamentary drawing functionality to an existing application. The drawings must be streamable both for input and output. The drawing is only streamable for output.  

You have been asked to support the GUI by providing the back end data storage and retrival as well as the drawing interface.  

The specification is unstable.  You should expect it to change.  

Specification:  

Users can create Line, Circle, and Polygon shapes.  

Users can also create arbitrary groupings of shapes to create new shapes.  

Drawings can be output for display by client code (not your code). You must support that effort by designing and providing an interface. Your code should provide a test case for exercising a drawing with adding, drawing, writing, and reading shapes.  

Persist a drawing to and from a text stream. Create an interface for drawing and demonstrate test usage by a client.  

You are authorized to use console output for the drawing display output test code.  

Tip:
-  It will be easier for you to explain your solution with the aid of a UML class diagram when you present.  
-  [JSON for Modern C++](https://github.com/nlohmann/json)  

###
