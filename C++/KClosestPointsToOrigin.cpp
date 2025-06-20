/*
leetcode problem #973: K Closest Points to Origin

Given an array of points where points[i] = [xi, yi] represents a point on 
the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance 
(i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique 
(except for the order that it is in).
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> solution;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0] * points[i][0];
            int y = points[i][1] * points[i][1];
            int distance = x + y;
            if (pq.size() < k) {
                pq.push({distance, i});
            } else {
               if (distance < pq.top().first) {
                pq.pop();
                pq.push({distance, i});
               } 
            }
        }

        while (!pq.empty()) {
            solution.push_back(points[pq.top().second]);
            pq.pop();
        }
        return solution;
    }
};