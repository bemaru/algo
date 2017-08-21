using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 버블정렬
{
    class Program
    {
        static void swap(ref int a, ref int b) {
            int temp = a;
            a = b;
            b = temp;
        }

        static void bubbleSort(int[] arr) {
            for (int i = 0; i < arr.Length - 1; i++) {
                for (int j = 1; j < arr.Length - i; j++) {
                    if (arr[j - 1] > arr[j]) {
                        swap(ref arr[j - 1], ref arr[j]);
                    }

                }
            }
        }

        static void printArray(int[] arr) {
            foreach (int i in arr) {
                Console.Write("{0} ", i);
            }
            Console.WriteLine();
        }
        
        static void Main(string[] args)
        {
            int[] array = new int[] { 6, 3, 9, 2, 10, 8, 5, 7, 1, 4 };
            printArray(array);
            bubbleSort(array);
            printArray(array);
        }
    }
}
