Given an integer array arr. You have to sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the sorted array.

 

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
Example 3:

Input: arr = [10000,10000]
Output: [10000,10000]
Example 4:

Input: arr = [2,3,5,7,11,13,17,19]
Output: [2,3,5,17,7,11,13,19]
Example 5:

Input: arr = [10,100,1000,10000]
Output: [10,100,10000,1000]
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 10^4


class Solution {
public:
    int intToBinary(int num)
    {
        int count = 0;
        while(num > 0)
        {
            if(num % 2)
                count++;
            num = num / 2;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        merge(arr, 0, arr.size() - 1);
        return arr;
    }
    void mergeSort(vector<int> &arr, int low, int mid, int high)
    {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        int left[n1];
        int right[n2];
        for(int i = 0; i < n1; i++)
        {
            left[i] = arr[low + i];
        }
        for(int i = 0; i < n2; i++)
        {
            right[i] = arr[mid + i + 1];
        }
        int i = 0, j = 0, k = low;
        while(i < n1 && j < n2)
        {
            int count1 = intToBinary(left[i]);
            int count2 = intToBinary(right[j]);
            if(count1 < count2)
            {
                arr[k] = left[i];
                i++;
                k++;
            }
            else if(count1 > count2)
            {
                arr[k] = right[j];
                j++;
                k++;
            }
            else
            {
                if(left[i] <= right[j])
                {
                    arr[k] = left[i];
                    i++;
                    k++;
                }
                else if(left[i] > right[j])
                {
                    arr[k] = right[j];
                    j++;
                    k++;
                }
                
            }
        }
        while(i < n1)
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        while(j < n2)
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    void merge(vector<int> &arr, int low, int high)
    {
        if(low < high)
        {
            int mid = (low + high) / 2;
            merge(arr, low, mid);
            merge(arr, mid + 1, high);
            mergeSort(arr, low, mid, high);
        }
    }
};
