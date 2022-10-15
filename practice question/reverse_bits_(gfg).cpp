

// long long reversedBits(long long X) {
//        uint32_t reverse=0;     #--> it is store the final result.
//        int pos=31;             #--> it is used to access the right most digit.   
//     while(pos>=0&&X)           #--> it will work until the either all the postition is moved or the number becomes zero(0)
//     {
//         if(X&1)                #--> it is AND operation between number and and 1
//         { 
//             reverse=reverse|(1<<pos);   
           
//         }
//         pos--;                         
//         X=X>>1;
//     }
//     return reverse;
//     }
