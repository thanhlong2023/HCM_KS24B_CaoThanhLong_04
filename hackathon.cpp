#include <bits/stdc++.h>

int arr[1000];
int main()
{
    int size = 0;
    while (1)
    {
        printf("1. Nhập số phần tử và giá trị cho mảng\n");
        printf("2. In ra giá trị các phần tử trong mảng theo dạng (arr[0] = 1, arr[1] = 5 …)\n");
        printf("3. Đếm số lượng các số hoàn hảo có trong mảng. Biết số hoàn hảo là số có tổng các ước bằng chính nó\n");
        printf("4. Tìm giá trị lớn thứ 2 trong mảng, không được sắp xếp mảng\n");
        printf("5. Thêm một phần tử vào vị trí ngẫu nhiên trong  mảng, phần tử mới thêm vào mảng và vị trí thêm vào phải do người dùng nhập vào\n");
        printf("6. Xóa phần tử tại một vị trí cụ thể (người dùng nhập vị trí)\n");
        printf("7. Sắp xếp mảng theo thứ tự tăng dần (Insertion sort)\n");
        printf("8. Cho người dùng nhập vào một phần tử, tìm kiếm xem phần tử đó có tồn tại trong mảng hay không (Binary search)\n");
        printf("9. Sắp xếp lại mảng và hiển thị ra toàn bộ phần tử có trong mảng sao cho toàn bộ số chẵn đứng trước, số lẻ đứng sau\n");
        printf("10. Đảo ngược thứ tự của các phần tử có trong mảng\n");
        printf("11. Thoát\n");
        int choice;
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            // 1. Nhập số phần tử và giá trị cho mảng
            int n;
            printf("Nhập số phần tử của mảng: ");
            getchar();
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("Nhập phần tử thứ %d: ", i);
                scanf("%d", &arr[i]);
            }
            size = n;
            printf("Tạo mảng thành công\n");
            break;
        }
        case 2:
        {
            // 2. In ra giá trị các phần tử trong mảng theo dạng (arr[0] = 1, arr[1] = 5 …)
            if (size == 0)
            {
                printf("Mảng rỗng\n");
                break;
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
            }
            break;
        }
        case 3:
        {
            // 3. Đếm số lượng các số hoàn hảo có trong mảng. Biết số hoàn hảo là số có tổng các ước bằng chính nó
            if (size == 0)
            {
                printf("Mảng rỗng\n");
                break;
            }
            else
            {
                int count = 0;
                for (int i = 0; i < size; i++)
                {
                    int sum = 0;
                    for (int j = 1; j < arr[i]; j++)
                    {
                        if (arr[i] % j == 0)
                        {
                            sum += j;
                        }
                    }
                    if (sum == arr[i])
                    {
                        count++;
                    }
                }
                if (count == 0)
                {
                    printf("Không có số hoàn hảo trong mảng\n");
                }
                else
                {
                    printf("Có %d số hoàn hảo trong mảng\n", count);
                }
            }
            break;
        }
        case 4:
        {
            // 4. Tìm giá trị lớn thứ 2 trong mảng, không được sắp xếp mảng
            if (size == 0)
            {
                printf("Mảng rỗng\n");
                break;
            }
            else
            {
                int max1 = -1e9, max2 = -1e9;
                for (int i = 0; i < size; i++)
                {
                    if (arr[i] > max1)
                    {
                        max2 = max1;
                        max1 = arr[i];
                    }
                    else if (arr[i] > max2 && arr[i] != max1)
                    {
                        max2 = arr[i];
                    }
                }
                printf("Giá trị lớn thứ 2 trong mảng là %d\n", max2);
            }
            break;
        }
        case 5:
        {
            //"5. Thêm một phần tử vào vị trí ngẫu nhiên trong  mảng, phần tử mới thêm vào mảng và vị trí thêm vào phải do người dùng nhập vào\n");
            if (size == 0)
            {
                printf("Mảng rỗng\n");
                break;
            }
            else
            {
                int value, index;
                printf("Nhập giá trị cần thêm: ");
                getchar();
                scanf("%d", &value);
                printf("Nhập vị trí cần thêm: ");
                getchar();
                scanf("%d", &index);
                if (index < 0 || index > size)
                {
                    printf("Vị trí không hợp lệ, mảng của bạn chỉ có %d phần tử\n", size);
                }
                else
                {
                    for (int i = size; i > index; i--)
                    {
                        arr[i] = arr[i - 1];
                    }
                    arr[index] = value;
                    size++;
                    printf("Thêm phần tử thành công\n");
                }
                for (int i = 0; i < size; i++)
                {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
            }
            break;
        }

        case 6:
        {
            // 6. Xóa phần tử tại một vị trí cụ thể (người dùng nhập vị trí)\n");
            if (size == 0)
            {
                printf("Mảng rỗng\n");
                break;
            }
            else
            {
                int index;
                printf("Nhập vị trí cần xóa: ");
                getchar();
                scanf("%d", &index);
                if (index < 0 || index >= size)
                {
                    printf("Vị trí không hợp lệ, mảng của bạn chỉ có %d phần tử\n", size);
                }
                else
                {
                    for (int i = index; i < size - 1; i++)
                    {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                    printf("Xóa phần tử thành công\n");
                }
                for (int i = 0; i < size; i++)
                {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
            }
            break;
        }
        case 7:
        {
            // printf("7. Sắp xếp mảng theo thứ tự tăng dần (Insertion sort)\n");
            if (size == 0)
            {
                printf("Mảng rỗng\n");
                break;
            }
            else
            {
                for (int i = 1; i < size; i++)
                {
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] > key)
                    {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Sắp xếp mảng thành công\n");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
            break;
        }
        case 8:
        {
            // 8. Cho người dùng nhập vào một phần tử, tìm kiếm xem phần tử đó có tồn tại trong mảng hay không (Binary search)\n");
            if (size == 0)
            {
                printf("Mảng rỗng\n");
                break;
            }
            else
            {
                int x;
                printf("Nhập giá trị cần tìm: ");
                scanf("%d", &x);
                int l = 0, r = size - 1;
                while (l <= r)
                {
                    int mid = l + (r - l) / 2;
                    if (arr[mid] == x)
                    {
                        printf("Phần tử %d có tồn tại trong mảng\n", x);
                        break;
                    }
                    else if (arr[mid] < x)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }
                if (l > r)
                {
                    printf("Phần tử %d không tồn tại trong mảng\n", x);
                }
            }
            break;
        }
        case 9:
        {
            // printf("9. Sắp xếp lại mảng và hiển thị ra toàn bộ phần tử có trong mảng sao cho toàn bộ số chẵn đứng trước, số lẻ đứng sau\n");
            if (size == 0)
            {
                printf("Mảng rỗng\n");
                break;
            }
            else
            {
                int chan[1000], le[1000];
                int size_chan = 0, size_le = 0;
                for (int i = 0; i < size; i++)
                {
                    if (arr[i] % 2 == 0)
                    {
                        chan[size_chan++] = arr[i];
                    }
                    else
                    {
                        le[size_le++] = arr[i];
                    }
                }
                for (int i = 0; i < size_chan; i++)
                {
                    arr[i] = chan[i];
                }
                for (int i = 0; i < size_le; i++)
                {
                    arr[size_chan + i] = le[i];
                }
                printf("Sắp xếp mảng thành công\n");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
            break;
        }
        case 10:
        {
            // printf("10. Đảo ngược thứ tự các phần tử có trong mảng\n");
            if (size == 0)
            {
                printf("Mảng rỗng\n");
                break;
            }
            else
            {
                int arr2[1000];
                for (int i = 0; i < size; i++)
                {
                    arr2[i] = arr[size - i - 1];
                }
                for (int i = 0; i < size; i++)
                {
                    arr[i] = arr2[i];
                }
                printf("Giá trị mảng sau khi đảo ngược: ");
                // for (int i = 0; i < size; i++)
                // {
                //     printf("%d ", arr2[i]);
                // }
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
            }
            break;
        }
        case 11:
        {
            break;
        }
        default:
        {
            printf("Lựa chọn không hợp lệ\n");
            break;
        }
        }

        if (choice == 11)
        {
            printf("Kết thúc chương trình\n");
            break;
        }
        printf("\n");
    }
}
// <3