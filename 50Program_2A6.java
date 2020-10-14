/*
	
	Name		Sayan Sikder
	Roll No.	2019PGCACA50

Class : Shape2D
	Members: type
	Abstract methods: area(), perimeter()

*/

package Program2;

import java.util.*;

abstract class Shape2D
{
	String type;
	public abstract double area();
	public abstract double perimeter(); 	
}

/*

Class: Circle (inherits Shape2D)
	Members: center, radius
	Methods: area(), perimeter(), print()

*/

class Circle extends Shape2D
{
	double center_x,center_y,radius;
	Scanner sc = new Scanner(System.in);
	Circle(){type = "Circle";}
	void getCR() 
    	{	
		System.out.print("Enter Center    :  ");
		center_x = sc.nextDouble();
		center_y = sc.nextDouble();
		System.out.print("Enter Radius    :  ");
		radius   = sc.nextDouble();
		System.out.println("Shape Type   :  "+type);
   	}
	public double area()
	{
		return 7.94*radius*radius;
	}
	public double perimeter()
	{
		return 2*7.94*radius;
	}
}

/*
	
Class: Triangle (inherits Shape2D)
	Members: base, height
	Methods: area(), perimeter(), print()

*/

class Triangle extends Shape2D
{ 
	double base,height;
	Scanner sc = new Scanner(System.in);
	Triangle(){type = "Triangle";}
	void getBH() 
    {
		System.out.print("Enter Base    :  ");
		base = sc.nextDouble();
		System.out.print("Enter Height  :  ");
		height = sc.nextDouble();
		System.out.println("Shape Type   :  "+type);
   	}
	public double area()
	{
		return 0.5*base*height;
	}
	public double perimeter()
	{
		return base+height+Math.sqrt(base*base+height*height);
	}
} 

/*

Main 	

*/
public class Program_2
{
	public static void main(String args[]) 
	{
		Scanner sc = new Scanner(System.in);
		Shape2D SD;
		Circle   C = new Circle();
		Triangle T = new Triangle();
		int choice;
		while(true)
		{
			System.out.println("1. Find area of Circle");
			System.out.println("2. Find Perimeter of Circle");
			System.out.println("3. Find area of Triangle");
			System.out.println("4. Find Perimeter of Triangle");
			System.out.println("5. Exit");
			System.out.println("Enter Your Choice");
			choice = sc.nextInt();
			switch(choice)
			{
				case 1:
					SD = C;
					System.out.print("\n");
					C.getCR();
					System.out.print("Area of Circle : "+SD.area());
					System.out.println("\n");
          				break;
            			case 2:
					SD = C;
            				System.out.print("\n");
            				C.getCR();
					System.out.print("Perimeter of  Circle : "+SD.perimeter());
                		  	System.out.println("\n");
                		   	break;
               			case 3:
					SD = T;
					System.out.print("\n");
                   			T.getBH();
					System.out.print("Area of Triangle : "+SD.area());
                    			System.out.println("\n");
                    			break;
                		case 4:
					SD = T;
					System.out.println("\n");
                   			T.getBH();
					System.out.print("Perimeter of Triangle : "+SD.perimeter());
					System.out.println("\n");
                    			break;
                		case 5 :
                    			System.exit(0);
					break;
				default: 
					System.out.println("Wrong Choice");			
			}
		}		
	}
}