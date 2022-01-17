#include <stdio.h>
#include <unistd.h>
void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
	{
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	new_nb;

	if (n == 0)
	{
		ft_putchar_fd (n + 48, fd);
	}
	else if (n > 0)
	{
		new_nb = n / 10;
		if (new_nb != 0)
		{
			ft_putnbr_fd(new_nb, fd);
		}
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		new_nb = 0 - (n / 10);
		if (new_nb != 0)
		{
			ft_putnbr_fd(new_nb, fd);
		}
		ft_putchar_fd(0 - (n % 10) + 48, fd);
	}
}


void printArray(int arr[], int size) 
{ 
    int i; 
    // ft_putchar_fd('a', 1);
    for (i = 0; i < size; i++) 
        {
            ft_putnbr_fd(arr[i], 1);
            ft_putchar_fd(' ', 1);
        }
    // ft_putchar_fd('a', 1);
}

 
// int partition(int a[],int l,int u)
// {
//     int v,i,j,temp;
//     v = a[l];
//     i = l + 1;
//     j = u;
//     if (i < j)
//     {
//         while(a[i] < v && i <= u)
//             i++;
//         while(v < a[j])
//             j--;
//         if(i < j)
//         {
//             temp=a[i];
//             a[i]=a[j];
//             a[j]=temp;
//         }
//     }
//             // a[l]=a[j];
//             // a[j]=v;
//             return(j);
// }

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    int j = low;

    while (j <= high - 1) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
        j++;
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
        }
}

int main ()
{
    int p[]= {22, 77, 33, 54, 8};

    // quick_sort(p, 0, 4);
    // printArray(p, 5);
    int i = 5;

    while(--i > 2)
    ft_putnbr_fd(i, 1);
    
    ft_putnbr_fd(i, 1);


}


/////////////////////////////////////////////////////////////

static int  scan_top_a(t_stack *st)
{
    int i;

    i = st->top_a;
    while (i >= 0 && st->stack_a[i] < st->stack_b[st->top_b])
        i--;
    return (st->top_a - (i + 1));
}

static int  scanـstack_b(t_stack *st)
{
    int i;

    i = st->top_b;
    while (i >= 0)
    {
        if (st->stack_a[0] < st->stack_b[i])
            return(0);
            i--;
    }
    return(1);
}

void    check_stack_a(t_stack *st)
{
    int small_num;
    int i;

    i = 0;
    small_num = scan_top_a(st);
    if (st->stack_a[0] == st->mark_bottom || st->stack_b[st->top_b] > st->stack_a[0])
    {
    while (i <= small_num && st->stack_a[st->top_a] < st->stack_b[st->top_b])
    {
        rot_a(st);
        i++;
    }
    }
    if (st->stack_b[st->top_b] < st->stack_a[st->top_a] && st->stack_b[st->top_b] > st->stack_a[0])
    {
        push_a(st);
        while (st->stack_a[0] < st->stack_a[st->top_a] && scanـstack_b(st))
        {
            revrot_a(st);
        }
    }

    // i = 0;
    // if (st->stack_a[0] != st->mark_bottom)
    // {
    // while (i <= small_num && scanـstack_b(st))
    // {
    //     // if (scanـstack_b(st) && st->stack_a[0] < st->stack_a[st->top_a])
    //         revrot_a(st);
    //     i++;
    // }
    // }
}

void    check_push_to_a(t_stack *st)
{
    if (st->stack_a[st->top_a] > st->stack_b[st->top_b])
        push_a(st);
    else
        check_stack_a(st);
}

void    part_b(t_stack *st)
{
    int i;
    int uu;

    i = 0;
    uu = st->top_a;
    st->mark_bottom = st->stack_a[0];
    while (i < st->ele_tot && st->top_b > -1)
    {
        check_push_to_a(st);
        i++; 
    }
}