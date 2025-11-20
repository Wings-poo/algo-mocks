/*
*OpenKattis
*imageprocessing
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int H, W, N, M;
    cin >> H >> W >> N >> M;

    int image[H][W];
    for (int h = 0; h < H; h++)
        for (int w = 0; w < W; w++)
            cin >> image[h][w];
    
    int kernel[N][M];
    for (int n = 0; n < N; n++)
        for (int m = 0; m < M; m++)
            cin >> kernel[n][m];
    
    for (int h = 0; h <= H - N; h++) {
        for (int w = 0; w <= W - M; w++) {
            int conv = 0;
            for (int i = h, n = N - 1; i < h + N; i++, n--) {
                for (int j = w, m = M - 1; j < w + M; j++, m--) {
                    //cout << image[i][j] << " " << n << " " << m << " " << kernel[n][m] << endl;
                    conv += image[i][j]*kernel[n][m];
                }
            }
            cout << conv << " ";
        }
        cout << endl;
    }
    
    return 0;
}