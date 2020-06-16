using System; 
using System.Collections; 
using System.Collections.Generic; 
 
class Arr { 
  
    // Driver code 
    public static void Main() 
    { 
  
        // Creating an ArrayList 
        ArrayList myList = new ArrayList(); 
  
        // Adding elements to ArrayList 
        myList.Add("Hello"); 
        myList.Add("World"); 
  
        Console.WriteLine("Count : " + myList.Count); 
        Console.WriteLine("Capacity : " + myList.Capacity); 
    } 
} 