#pragma once
#include <vector>

class Board {
public:
    Board(int n, int n_in_row, int cur_player = 1);

    void exec_move(int pos);
    void exec_move(int x, int y);
    std::vector<int> get_moves() const;
    bool is_legal(int pos) const;
    bool is_legal(int x, int y) const;
    void display() const;
    int get_board_size() const;
    bool get_is_tie() const;

    // torch input states
    std::vector<std::vector<std::vector<int>>> get_encode_states() const;

    int get_n() const { return n; }
    int get_cur_player() const { return cur_player; }
    int get_last_move() const { return last_move; }
    int get_move_cnt() const { return move_cnt; }
    std::vector<std::vector<int>> get_states() const { return states; }
    std::pair<bool, int> get_result() const { return result; }
private:
    std::vector<std::vector<int>> states;  // board states, -1/1/0
    int n = 15;
    int n_in_row = 5;
    int cur_player = 1;
    int last_move = -1;
    int move_cnt = 0;
    std::pair<bool, int> result{false, 0}; // (is ended, winner)
};