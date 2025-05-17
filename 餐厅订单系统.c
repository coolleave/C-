#include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// typedef struct {
//     char name[50];
//     float price;
// } Dish;

// Dish menu[] = {
//     {"红烧肉", 25.0},
//     {"宫保鸡丁", 18.0},
//     {"鱼香肉丝", 20.0},
//     {"糖醋里脊", 22.0},
//     {"水煮鱼", 30.0}
// };

// void displayMenu() {
//     printf("欢迎光临！这是我们的菜单：\n");
//     for (int i = 0; i < sizeof(menu) / sizeof(Dish); i++) {
//         printf("%d. %s - ￥%.2f\n", i+1, menu[i].name, menu[i].price);
//     }
//     printf("\n");
// }

// float addToCart(float total) {
//     int dishIndex;
//     printf("请输入要加入购物车的菜品编号（输入 0 结束）：");
//     scanf("%d", &dishIndex);

//     while (dishIndex != 0 && (dishIndex < 1 || dishIndex > sizeof(menu) / sizeof(Dish))) {
//         printf("无效的菜品编号，请重新输入（输入 0 结束）：");
//         scanf("%d", &dishIndex);
//     }

//     if (dishIndex != 0) {
//         total += menu[dishIndex-1].price;
//         printf("已将 %s 加入购物车。当前总价为：￥%.2f\n\n", menu[dishIndex-1].name, total);
//         return addToCart(total);
//     } else {
//         return total;
//     }
// }

// void checkout(float total) {
//     printf("您选择了以下菜品：\n");
//     float subTotal = 0.0;
//     int count = 0;

//     while (total > 0.0) {
//         int dishIndex = rand() % (sizeof(menu) / sizeof(Dish));
//         if (total >= menu[dishIndex].price) {
//             printf("%d. %s - ￥%.2f\n", ++count, menu[dishIndex].name, menu[dishIndex].price);
//             subTotal += menu[dishIndex].price;
//             total -= menu[dishIndex].price;
//         }
//     }

//     printf("总价：￥%.2f\n", subTotal);
//     printf("感谢您的光临！祝您用餐愉快！\n\n");
// }

int main() {
    // srand((unsigned int)time(NULL)); // 初始化随机数生成器

    // while (1) {
    //     printf("请选择操作：\n");
    //     printf("1. 查看菜单\n");
    //     printf("2. 加入购物车\n");
    //     printf("3. 结算与支付\n");
    //     printf("4. 退出\n");
    //     printf("请输入您的选择：");

        int choice;
        scanf("%d", &choice);

        // switch (choice) {
        //     case 1:
        //         displayMenu();
        //         break;
            // case 2:
            //     printf("请开始点餐吧！\n");
            //     float total = addToCart(0.0);
            //     printf("您的购物车中共有 %.0f 件商品，总价为：￥%.2f\n\n", total / 5.0, total);
            //     break;
            // case 3:
            //     checkout(total);
            //     break;
            // case 4:
            //     printf("谢谢您的使用！再见！\n");
            //     exit(0);
        //     default:
        //         printf("无效的选择。\n\n");
        //         break;
        // }
    // }

    return 0;
}