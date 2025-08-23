#code by hluan(@luaniikvi) - 24162069
import json
from collections import Counter

dataSaveFile = "milkTeaData.json"
def saveData(filename, data):
    with open(filename, "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=4)
def loadData(filename):
    try:
        with open(filename, "r", encoding="utf-8") as f:
            return json.load(f)
    except:
        return []

size    = ["700ml", "500ml"]
tea     = ['Hồng trà', 'Lục trà', 'Ô long']
milk    = ['Sữa tươi', 'Sữa hạnh nhân', 'Sữa yến mạch']
sugar   = ['0%', '30%', '50%', '70%', '100%']
ice     = ['Không đá', 'Ít đá', 'Vừa', 'Nhiều đá']
topping = ['Trân châu đen', 'Trân châu trắng', 'Thạch trái cây', 'Thạch cà phê', 'Pudding trứng', 'Kem cheese']


salesData = loadData(dataSaveFile)
orderID   = 1 if salesData == [] else salesData[-1]["orderID"] + 1


def getCustomerChoice() -> dict:
    print("\nChọn kích thước:")
    for i,item in enumerate(size):
        print(f"{i+1}. {item}")
    sizeChoice = int(input("Choose your size: ")) - 1
    while sizeChoice < 0 or sizeChoice >= len(size):
        print("-- Không hợp lệ, vui lòng chọn lại --")
        sizeChoice = int(input("Choose your size: ")) - 1


    print("\nChọn nền trà (tea base):")
    for i,item in enumerate(tea):
        print(f"{i+1}. {item}")
    teaChoice = int(input("Choose your tea: ")) - 1
    while teaChoice < 0 or teaChoice >= len(tea):
        print("-- Không hợp lệ, vui lòng chọn lại --")
        teaChoice = int(input("Choose your tea: ")) - 1


    print("\nChọn sữa:")
    for i,item in enumerate(milk):
        print(f"{i+1}. {item}")
    milkChoice = int(input("Choose your milk: ")) - 1
    while milkChoice < 0 or milkChoice >= len(milk):
        print("-- Không hợp lệ, vui lòng chọn lại --")
        milkChoice = int(input("Choose your milk: ")) - 1


    print("\nChọn đường:")
    for i,item in enumerate(sugar):
        print(f"{i+1}. {item}")
    sugarChoice = int(input("Choose your sugar: ")) - 1
    while sugarChoice < 0 or sugarChoice >= len(sugar):
        print("-- Không hợp lệ, vui lòng chọn lại --")
        sugarChoice = int(input("Choose your sugar: ")) - 1


    print("\nChọn đá:")
    for i,item in enumerate(ice):
        print(f"{i+1}. {item}")
    iceChoice = int(input("Choose your ice: ")) - 1
    while iceChoice < 0 or iceChoice >= len(ice):
        print("-- Không hợp lệ, vui lòng chọn lại --")
        iceChoice = int(input("Choose your ice: ")) - 1


    print("\nChọn tối đa 3 loại topping:")
    for i, item in enumerate(topping):
        print(f"{i + 1}. {item}")
    toppingChoice = input("Nhập lựa chọn của bạn, ngăn cách bởi dấu phẩy (VD: 1,3,5): ").split(",")
    toppingChoice = [int(i) for i in toppingChoice]
    while len(toppingChoice) > 3 or not(all(n>0 for n in toppingChoice)):
        print("-- Không hợp lệ, vui lòng chọn lại --")
        toppingChoice = input("Nhập lựa chọn của bạn, ngăn cách bởi dấu phẩy (VD: 1,3,5): ").split(",")
        toppingChoice = [int(i) for i in toppingChoice]
    toppingChoice = [topping[i-1] for i in toppingChoice]


    return {
        "size": size[sizeChoice],
        "tea": tea[teaChoice],
        "milk": milk[milkChoice],
        "sugar": sugar[sugarChoice],
        "ice": ice[iceChoice],
        "topping": toppingChoice
    }


def editOrder(order):
    print("\nChọn thành phần cần sửa:")
    print("1. Kích thước")
    print("2. Nền trà (tea base)")
    print("3. Sữa")
    print("4. Lượng đường")
    print("5. Lượng đá")
    print("6. Topping")
    edit  = int(input("Edit (1-6): "))
    while edit < 1 or edit > 6:
        print("-- Không hợp lệ, vui lòng chọn lại --")
        edit  = int(input("Edit (1-6): "))

    if edit == 1:
        print("\nChọn kích thước:")
        for i, item in enumerate(size):
            print(f"{i + 1}. {item}")
        order["size"] = int(input("Choose your size: ")) - 1
        while order["size"] < 0 or order["size"] >= len(size):
            print("-- Không hợp lệ, vui lòng chọn lại --")
            order["size"] = int(input("Choose your size: ")) - 1
        order["size"] = size[order["size"]]
    elif edit == 2:
        print("\nChọn nền trà (tea base):")
        for i, item in enumerate(tea):
            print(f"{i + 1}. {item}")
        order["tea"] = int(input("Choose your tea: ")) - 1
        while order["tea"] < 0 or order["tea"] >= len(tea):
            print("-- Không hợp lệ, vui lòng chọn lại --")
            order["tea"] = int(input("Choose your tea: ")) - 1
        order["tea"] = tea[order["tea"]]
    elif edit == 3:
        print("\nChọn sữa:")
        for i, item in enumerate(milk):
            print(f"{i + 1}. {item}")
        order["milk"] = int(input("Choose your milk: ")) - 1
        while order["milk"] < 0 or order["milk"] >= len(milk):
            print("-- Không hợp lệ, vui lòng chọn lại --")
            order["milk"] = int(input("Choose your milk: ")) - 1
        order["milk"] = milk[order["milk"]]
    elif edit == 4:
        print("\nChọn đường:")
        for i, item in enumerate(sugar):
            print(f"{i + 1}. {item}")
        order["sugar"] = int(input("Choose your sugar: ")) - 1
        while order["sugar"] < 0 or order["sugar"] >= len(sugar):
            print("-- Không hợp lệ, vui lòng chọn lại --")
            order["sugar"] = int(input("Choose your sugar: ")) - 1
        order["sugar"] = sugar[order["sugar"]]
    elif edit == 5:
        print("\nChọn đá:")
        for i, item in enumerate(ice):
            print(f"{i + 1}. {item}")
        order["ice"] = int(input("Choose your ice: ")) - 1
        while order["ice"] < 0 or order["ice"] >= len(ice):
            print("-- Không hợp lệ, vui lòng chọn lại --")
            order["ice"] = int(input("Choose your ice: ")) - 1
        order["ice"] = ice[order["ice"]]
    else:
        print("\nChọn tối đa 3 loại topping:")
        for i, item in enumerate(topping):
            print(f"{i + 1}. {item}")
        order["topping"] = input("Nhập lựa chọn của bạn, ngăn cách bởi dấu phẩy (VD: 1,3,5): ").split(",")
        order["topping"] = [int(i) for i in order["topping"]]
        while len(order["topping"]) > 3 or not (all(n > 0 for n in order["topping"])):
            print("-- Không hợp lệ, vui lòng chọn lại --")
            order["topping"] = input("Nhập lựa chọn của bạn, ngăn cách bởi dấu phẩy (VD: 1,3,5): ").split(",")
            order["topping"] = [int(i) for i in order["topping"]]
        order["topping"] = [topping[i - 1] for i in order["topping"]]

    return order


def summary():
    teaCounter       = Counter()
    milkCounter      = Counter()
    sugarCounter     = Counter()
    iceCounter       = Counter()
    toppingCounter   = Counter()

    for order in salesData:
        for data in order["data"]:
            teaCounter[data["tea"]] += 1
            milkCounter[data["milk"]]      += 1
            sugarCounter[data["sugar"]]    += 1
            iceCounter[data["ice"]]        += 1
            for item in data["topping"]:
                toppingCounter[item] += 1

    print("\nLoại trà đã bán:")
    for name,count in teaCounter.items():
        print(f"- {name}: {count}")
    most = teaCounter.most_common(1)[0]
    least = min(teaCounter.items(), key=lambda x: x[1])
    print(f"  --> Loại phổ biến nhất: {most[0]} | số lượng: {most[1]}")
    print(f"  --> Loại ít phổ biến nhất: {least[0]} | số lượng: {least[1]}")


    print("\nLoại sữa đã bán:")
    for name,count in milkCounter.items():
        print(f"- {name}: {count}")
    most = milkCounter.most_common(1)[0]
    least = min(milkCounter.items(), key=lambda x: x[1])
    print(f"  --> Loại phổ biến nhất: {most[0]} | số lượng: {most[1]}")
    print(f"  --> Loại ít phổ biến nhất: {least[0]} | số lượng: {least[1]}")


    print("\nLượng đường đã bán:")
    for name,count in sugarCounter.items():
        print(f"- {name}: {count}")


    print("\nLượng đá đã bán:")
    for name,count in iceCounter.items():
        print(f"- {name}: {count}")


    print("\nLoại topping đã bán:")
    for name,count in toppingCounter.items():
        print(f"- {name}: {count}")
    most = toppingCounter.most_common(1)[0]
    least = min(toppingCounter.items(), key=lambda x: x[1])
    print(f"  --> Loại phổ biến nhất: {most[0]} | số lượng: {most[1]}")
    print(f"  --> Loại ít phổ biến nhất: {least[0]} | số lượng: {least[1]}")


def main():
    orderList = []
    while True:
        currentOrder = getCustomerChoice()
        print("\nĐơn hàng của bạn:")
        for item,option in currentOrder.items():
            print(f"- {item}: {option}")

        print("\nTùy chỉnh đơn hàng: ")
        print("1. Xác nhận đơn hàng")
        print("2. Sửa đơn hàng")
        print("3. Hủy đơn")
        confirm = int(input("Choose your choice: "))
        while confirm < 1 or confirm > 3:
            print("-- Không hợp lệ, vui lòng chọn lại --")
            confirm = int(input("Choose your choice: "))

        #Hủy đơn
        if confirm == 3:
            print("Đơn đã bị hủy")
        #Sửa đơn
        elif confirm == 2:
            while confirm == 2:
                currentOrder = editOrder(currentOrder)
                print("\nĐơn hàng của bạn:")
                for item, option in currentOrder.items():
                    print(f"- {item}: {option}")
                print("\nTùy chỉnh đơn hàng: ")
                print("1. Xác nhận đơn hàng")
                print("2. Sửa đơn hàng")
                print("3. Hủy đơn")
                confirm = int(input("Choose your choice: "))
                while confirm < 1 or confirm > 3:
                    print("-- Không hợp lệ, vui lòng chọn lại --")
                    confirm = int(input("Choose your choice: "))
        # Xác nhận
        else:
            orderList.append(currentOrder)

        #Order thêm
        conitinueOrder = input("Tiếp tục đặt (y/n)?: ")
        if conitinueOrder.lower() == 'y':
            pass
        else:
            print(f"Mã đơn hàng {orderID}")
            salesData.append({"orderID": orderID, "data": orderList})
            saveData(dataSaveFile,salesData)
            break

    #Tổng kết Order
    #summary()



if __name__ == "__main__":
    main()