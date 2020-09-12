I main() 
{ 
    C arr[5][4];
    arr[0][2] = 5>4?'a':'b'; 
    arr[1] = 'r'; 
    arr[2] = 'x'; 
    arr[3] = 'y'; 
    arr[4] = 'z'; 
    I n;
    n = sizeof(arr) / sizeof(arr[0]); 
  
    insertionSort(arr, n); 
    printArray(arr, n); 
  
    RET 0; 
} 