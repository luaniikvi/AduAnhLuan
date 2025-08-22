import json
from collections import Counter

sizeOptions      = ["Lớn (500ml)","Nhỏ (250ml)"]
coffeTypeOptions = ["Espresso", "Latte", "Cappuccino"]
milkOptions      = ["Fresh milk", "Almond milk" , "Oat milk"]
toppingOptions   = ["Whipped cream", "Caramel", "Chocolate", "Cinnamon", "Ice blended"]

def SaveSalesData(filename, salesData):
    with open(filename, "w", encoding="utf-8") as f:
        json.dump(salesData, f, ensure_ascii=False, indent=4)

def LoadSalesData(filename):
    try:
        with open(filename, "r", encoding="utf-8") as f:
            return json.load(f)
    except:
        return []

salesData = LoadSalesData("data.json")
if salesData != [] : orderID = salesData[-1]["orderID"] + 1
else : orderID = 1

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
    toppingChoice = input("Nhập lựa chọn của bạn, ngăn cách bởi dấu phẩy (VD: 1,3,5): ").split(",")
    toppingChoice = [int(i) for i in toppingChoice]

    while len(toppingChoice) > 3 or all(n <= 0 for n in toppingChoice):
        toppingChoice = input("Nhập lựa chọn của bạn, ngăn cách bởi dấu phẩy (VD: 1,3,5): ").split(",")
        toppingChoice = [int(i) for i in toppingChoice]

    toppingChoice = [toppingOptions[i-1] for i in toppingChoice]

    return {
        "size": sizeOptions[sizeChoice],
        "coffeType": coffeTypeOptions[coffeTypeChoice],
        "milk": milkOptions[milkChoice],
        "topping": toppingChoice
    }

def RecordChoice(orderList , salesData):
    salesData.append({"orderID": orderID, "data": orderList})

def ShowRecord(salesData):
    for order in salesData:
        print(f"\n  Mã đơn hàng(ID): {order["orderID"]}")
        for i,data in enumerate(order["data"]):
            print(f"{i+1}. {data}")

def Count(salesData):
    coffee_counter = Counter()
    milk_counter = Counter()
    topping_counter = Counter()

    for order in salesData:
        for data in order["data"]:
            coffee_counter[data["coffeType"]] += 1
            milk_counter[data["milk"]] += 1
            for topping in data.get("topping", []):  # lặp qua list topping
                topping_counter[topping] += 1

    print("\n Loại cà phê đã bán:")
    for coffee, count in coffee_counter.items():
        print(f"- {coffee}: {count}")

    print("\n Loại sữa đã bán:")
    for milk, count in milk_counter.items():
        print(f"- {milk}: {count}")

    print("\n Topping đã bán:")
    for topping, count in topping_counter.items():
        print(f"- {topping}: {count}")


def main():
    customerOrderList = []
    while True:
        global orderID
        currentOrder = GetCustomerChoice()

        print(f"Đơn hàng của bạn: {currentOrder}")
        confirm = input("Xác nhận đơn hàng? (y/n): ")
        if confirm.lower() == 'y':
            print(f"Đơn hàng đã được xác nhận!")
            customerOrderList.append(currentOrder)

        else:
            print("Đơn hàng đã bị hủy")


        continueOrder = input("Tiếp tục đặt hàng? (y/n): ")
        if continueOrder.lower() != 'y':
            print(f"Mã đơn hàng: {orderID}")
            RecordChoice(customerOrderList, salesData)
            SaveSalesData("data.json", salesData)
            break

    print("Số liệu bán hàng cuối ngày:")
    ShowRecord(salesData)
    Count(salesData)
main()