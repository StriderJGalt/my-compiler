B insertionSort(I arr[], I n) 
{ 
    I key = 0;
    I j = 0; 
    FOR (I i = 1; i < n; i=i+1;)
    { 
        key = arr[i]; 
        j = i - 1; 
        WHILE (j >= 0 & arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
    RET 1;
} 
  
  
I main() 
{ 
    I arr[5];
    I n = 5;

    FOR (I i=0;i<n;i=i+1;)
    {
        B f = scan("%d",arr[i]);
    }

    f = insertionSort(arr, n); 
    
    FOR (I j=0;j<n;j=j+1;)
    {
        f = print("%d ",arr[j]);
    } 
  
    RET 0; 
} 
