sizeOptions    = ["Lớn (500ml)","Nhỏ (250ml)"]
coffeTypeOptions = ["Espresso", "Latte", "Cappuccino"]
milkOptions    = ["Fresh milk", "Almond milk" , "Oat milk"]
toppingOptions = ["Whipped cream", "Caramel", "Chocolate", "Cinnamon", "Ice blended"]

salesData = {
    "size": {"Lớn (500ml)": 0, "Nhỏ (250ml)": 0},
    "coffeType" : {"Espresso": 0, "Latte": 0 , "Cappuccino": 0},
    "milk" : {"Fresh milk": 0, "Almond milk": 0 , "Oat milk": 0}
}

def GetCustomerChoice():
    print("Chọn kích thước cà phê:")
    for i,option in enumerate(sizeOptions):
        print(f"{i+1}. {option}")
    sizeChoice = int(input("Choose a size(1-2): ")) - 1
    while sizeChoice < 0 or sizeChoice > 1:
        sizeChoice = int(input("Choose a size(1-2): ")) - 1

    print("Chọn cách loại coffe:")
    for i,option in enumerate(coffeTypeOptions):
        print(f"{i+1}. {option}")
    coffeTypeChoice = int(input("Choose type(1-3): ")) - 1
    while coffeTypeChoice < 0 or coffeTypeChoice > 2:
        coffeTypeChoice = int(input("Choose type(1-3): ")) - 1

    print("Chọn loại sữa:")
    for i,option in enumerate(milkOptions):
        print(f"{i+1}. {option}")
    milkChoice = int(input("Choose milk(1-3): ")) - 1
    while  milkChoice < 0 or milkChoice > 2:
        milkChoice = int(input("Choose milk(1-3): ")) - 1

    print("Chọn tối đa 3 loại topping:")
    for i, topping in enumerate(toppingOptions):
        print(f"{i + 1}. {topping}")
    toppingChoice = input("Nhập lựa chọn của bạn, ngăn cách bởi dấu phẩy (VD: 1,3,5): ")
    while len(toppingChoice.split(",")) > 3 or ("0" in toppingChoice) or ('-' in toppingChoice):
        toppingChoice = input("Nhập lựa chọn của bạn, ngăn cách bởi dấu phẩy (VD: 1,3,5): ")
    toppingChoice = toppingChoice.split(",")
    toppingChoice = [toppingOptions[int(i) - 1] for i in toppingChoice]

    return {
        "size": sizeOptions[sizeChoice],
        "coffeType": coffeTypeOptions[coffeTypeChoice],
        "milk": milkOptions[milkChoice],
        "topping": toppingChoice
    }

def RecordChoise(order , salesData):
    salesData["size"][order["size"]] += 1
    salesData["coffeType"][order["coffeType"]] += 1
    salesData["milk"][order["milk"]] += 1

def Summary(salesData):
    mostPopular = max(salesData["coffeType"], key=salesData["coffeType"].get)
    print(f"Most popular: {mostPopular} | amount: {salesData["coffeType"][mostPopular]}")

    leastPopular = min(salesData["coffeType"], key=salesData["coffeType"].get)
    print(f"Least popular: {mostPopular} | amount: {salesData["coffeType"][mostPopular]}")


def main():
    orderNumber = 1
    while True:
        customerOrder = GetCustomerChoice()
        print(f"Đơn hàng của bạn: {customerOrder}")
        confirm = input("Xác nhận đơn hàng? (y/n): ")
        if confirm.lower() == 'y':
            print(f"Đơn hàng đã được xác nhận. Mã đơn hàng: {orderNumber}")
            orderNumber += 1
            RecordChoise(customerOrder, salesData)
        else:
            print("Đơn hàng đã bị hủy")
        continueOrder = input("Tiếp tục đặt hàng? (y/n): ")
        if continueOrder.lower() != 'y':
            break

    print("Số liệu bán hàng cuối ngày:", salesData)
    Summary(salesData)

main()