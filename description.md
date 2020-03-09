Comparing all the three file allocation methods(Contiguous, Linked List, Indexed) 
I came to the conclusion that the best file allocation method is Indexed File Allocation. 
The Contiguous File Allocation method suffers a lot of external fragmentation but it’s access
time is and lesser than Linked list File allocation method as it uses the
concept of direct access of files whereas Linked List File Allocation method
doesn’t suffers from external fragmentation but it has a larger file access time
as it follows sequential access method.

Indexed File Allocation Method is free of external fragmentation
and it uses the random access method to access a file which is faster in all
three allocation methods. Hence, the Indexed file allocation is comparatively
the best file allocation method in all the three file allocation methods. But
the main problems in the Indexed file allocation method is that for a large
size file, it is very difficult for single index block to hold all the pointers.
Hence, we can’t store large files using this method and For very small files say
files that expend only 2-3 blocks the indexed allocation would keep on the
entire block for the pointers which is insufficient in terms of memory
utilization and hence it suffers from a wastage of space.

To minimise the disadvantages of all the three file allocation
method we need a new improvised or hybridised file allocation method
and the solution to problem given statement above is given below.

As we already saw that the Indexed File Allocation Method is the
best file allocation method in all three File Allocation methods and also that
the Linked List File Allocation method is better than Contiguous File Allocation
method, So it will be a good idea if we try to combine the Linked List File
Allocation method and Indexed File Allocation Method.

My File allocation method will basically implement Linked List File
Allocation method but I will fix a particular number for the size of the file
after which Indexed File Allocation Method implementation takes place. The
main advantage of this method will be that very small files say files that
expend only 2-3 blocks the indexed allocation would not keep on the entire
block for the pointers which is insufficient in terms of memory utilization and
hence it will not suffer from wastage of space.

My next idea for our proposed File Allocation method is that
instead of having one indexed block we will have two indexed blocks
in which, half of the pointers of the allocated blocks will be stored in one
indexed block while the other half pointers of the allocated blocks will be
stored in another indexed block. The advantage of this method will be that
the problem of not being able to store a large file due to not being capable to
store all the pointers in one indexed block will be terminated.

The user will be asked for maximum size of the block upto which Linked list file
allocation will be implemented and maximum file size upto which indexed file allocation
will be implemented. Suppose, the
user enters 10 as the maximum size of the block upto which Linked list file allocation
will be implemented and 20 as the maximum size of the block upto which Indexed file
allocation will be implemented thus after size 20 ofthe file my modified file
allocation method will be implemented. 

Thus for the file size less than 10 normal linked list file allocation will be
implemented, for file size in between 10 and 20 normal indexed file allocation and for
file size greater than 20 our proposed modified file allocation method will be
implemented which has two indexed blocks for storing larger files all pointers.

Thus, this is how I minimized the external fragmentation and the file access
time in my new proposed file allocation method and made my file allocation method more
efficient than the existing ones.
