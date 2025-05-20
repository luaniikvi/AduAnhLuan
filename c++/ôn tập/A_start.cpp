#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct Point {
    int x=-1, y=-1;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const Point& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
};

struct Node {
    Point pt;
    double g; 
    double h;
    double f;
    Point parent;

    // Constructor
    Node(Point p, double g_cost, double h_cost, Point par) : pt(p), g(g_cost), h(h_cost), f(g_cost + h_cost), parent(par) {}
     Node() : pt({-1, -1}), g(-1.0), h(-1.0), f(-1.0), parent({-1, -1}) {} // Default constructor

    bool operator<(const Node& other) const {
        return f > other.f; 
    }
};

// Hàm heuristic (khoảng cách Manhattan)
double calculate_h(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

// Kiểm tra xem một điểm có hợp lệ (nằm trong ma trận và không phải là tường) hay không
bool is_valid(Point p, int rows, int cols, const vector<string>& matrix) {
    // Điểm hợp lệ nếu nằm trong ma trận VÀ không phải là tường '#'
    return (p.x >= 0 && p.x < rows && p.y >= 0 && p.y < cols && matrix[p.x][p.y] != '#');
}

// Các hướng di chuyển (lên, xuống, trái, phải)
int row_num[] = {-1, 1, 0, 0};
int col_num[] = {0, 0, -1, 1};

// Thuật toán A*
vector<Point> a_star(const vector<string>& matrix, Point start, Point end) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Closed list để lưu các ô đã xử lý
    set<Point> closed_list;

    // Priority queue cho open list, lưu trữ các node cần được khám phá, ưu tiên node có f nhỏ nhất
    priority_queue<Node> open_list;

    // Vector để lưu trữ thông tin chi phí và cha của mỗi ô
    vector<vector<Node>> cell_details(rows, vector<Node>(cols)); // Sử dụng default constructor

    // Khởi tạo điểm bắt đầu
    cell_details[start.x][start.y] = Node(start, 0.0, calculate_h(start, end), {-1, -1});
    open_list.push(cell_details[start.x][start.y]);

    while (!open_list.empty()) {
        // Lấy node có f nhỏ nhất từ open list
        Node current_node = open_list.top();
        open_list.pop();

        Point current_pt = current_node.pt;

        // Nếu ô hiện tại đã có trong closed list, bỏ qua (có thể xảy ra do push nhiều lần vào priority_queue)
        if (closed_list.count(current_pt)) {
            continue;
        }

        // Đã đến đích
        if (current_pt == end) {
            vector<Point> path;
            Point current = end;
            while (!(current.x == -1 && current.y == -1)) {
                path.push_back(current);
                // Đảm bảo parent tồn tại trước khi truy cập
                 if(cell_details[current.x][current.y].parent.x == -1 && cell_details[current.x][current.y].parent.y == -1 && !(current == start)) {
                    // Đây là trường hợp lỗi, parent của điểm không phải start lại là {-1,-1}
                     break;
                 }
                current = cell_details[current.x][current.y].parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // Thêm node hiện tại vào closed list
        closed_list.insert(current_pt);

        // Khám phá các ô lân cận
        for (int i = 0; i < 4; ++i) {
            Point neighbor_pt = {current_pt.x + row_num[i], current_pt.y + col_num[i]};

            // Kiểm tra tính hợp lệ của ô lân cận
            if (is_valid(neighbor_pt, rows, cols, matrix)) {
                // Nếu ô lân cận chưa có trong closed list
                if (closed_list.find(neighbor_pt) == closed_list.end()) {
                    double new_g = current_node.g + 1.0; // Chi phí di chuyển đến ô lân cận là 1
                    double new_h = calculate_h(neighbor_pt, end);
                    double new_f = new_g + new_h;

                    // Nếu ô lân cận chưa được khám phá (f == -1.0) hoặc tìm thấy đường đi tốt hơn
                    if (cell_details[neighbor_pt.x][neighbor_pt.y].f == -1.0 || new_f < cell_details[neighbor_pt.x][neighbor_pt.y].f) {
                        // Cập nhật thông tin cho ô lân cận
                        cell_details[neighbor_pt.x][neighbor_pt.y] = Node(neighbor_pt, new_g, new_h, current_pt);
                        // Thêm ô lân cận vào open list
                        open_list.push(cell_details[neighbor_pt.x][neighbor_pt.y]);
                    }
                }
            }
        }
    }

    // Không tìm thấy đường đi
    return {};
}

int main() {
    int m,n; cin >> m >> n;

    vector<string> matrix(m);
    Point start,end;

    for(int i=0 ; i< m ; i++)
    {
        cin >> matrix[i];
        for(int j=0 ; i<n ; j++)
        {
            if(matrix[i][j] == 'A') start = {i,j};
            else if(matrix[i][j] == 'B') end = {i,j};
        }
    }


    int rows = matrix.size();
    int cols = matrix[0].size();

    // Tìm điểm A và B trong ma trận
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 'A') {
                start = {i, j};
            } else if (matrix[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    // Kiểm tra xem đã tìm thấy cả điểm A và B chưa
    if (start.x == -1 || end.x == -1) {
        cout << "Khong tim thay diem A hoac diem B trong ma tran." << endl;
        return 1;
    }

    // Thay thế 'A' và 'B' bằng '.' trong ma trận để thuật toán xử lý như đường đi
    vector<string> matrix_for_astar = matrix;
    matrix_for_astar[start.x][start.y] = '.';
    matrix_for_astar[end.x][end.y] = '.';


    vector<Point> path = a_star(matrix_for_astar, start, end);

    // path : đường đi , empty() -> null || inf
        

    return 0;
}