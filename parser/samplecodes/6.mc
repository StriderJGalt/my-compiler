B insertionSort(I arr[], I n) 
{ 
    I key, j; 
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
  
  
I MAIN() 
{ 
    I arr[5],n;
    n = 5;

    FOR (I i=0;i<n;i=i+1;)
    {
        scan("%d",arr[i]);
    }

    insertionSort(arr, n); 
    
    FOR (I i=0;i<n;i=i+1;)
    {
        print("%d ",arr[i]);
    } 
  
    RET 0; 
} 
