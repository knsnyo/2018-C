#include <stdio.h> // 총알 피하기 게임
#include <conio.h> // getch() kbhit()
#include <stdlib.h> // rand() srand()
#include <time.h> // time()
#include <windows.h> //system("cls") Sleep(); ms초로 멈춤

// 키보드는 (224,?)를 반환함
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

void main()
{
	// 게임 그 자체
	while (1)
	{
		// 맵 // 0은 공백 // 1은 벽
		int pan[11][11] =
		{
			{ 1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1 }
		};

		// player == 2
		int player_x = 5; // 배열 x
		int player_y = 5; // 배열 y
		pan[player_x][player_y] = 2; // 정 중앙에 위치
		int key = 0; // 방향키를 입력받을 예정

		// 총알 관련
		long seconds = (long)time(NULL);
		srand(seconds);

		// 아래에서 위로 감
		int bulletU = 3;
		int bUX = 9;
		int bUY = rand() % 9 + 1;
		pan[bUX][bUY] = 3; // 총알
		// 위에서 아래로 감
		int bulletD = 3;
		int bDX = 1;
		int bDY = rand() % 9 + 1;
		pan[bDX][bDY] = 3; // 총알
		// 오른쪽에서 왼쪽으로 감
		int bulletL = 3;
		int bLX = rand() % 9 + 1;
		int bLY = 9;
		pan[bLX][bLY] = 3; // 총알
		// 왼쪽에서 오른쪽으로 감
		int bulletR = 3;
		int bRX = rand() % 9 + 1;
		int bRY = 1;
		pan[bRX][bRY] = 3; // 총알

		// 점수
		int point = 0; // 총알을 피할때마다 증가 할 예정

		// 게임 시작
		while (1)
		{
			printf("made by 18114875 김장현!\n");
			printf("방향키로 ○를 움직여서 ★를 피하세요!\n");
			printf("키보드를 빠르게 연타시 안보이실수 있습니다....\n");
			//판 그리기
			for (int i = 0; i < 11; i++)
			{
				for (int j = 0; j < 11; j++)
				{
					if (pan[i][j] == 0) // 빈공간
					{
						printf("  ");
					}
					else if (pan[i][j] == 1) // 벽
					{
						printf("■");
					}
					else if (pan[i][j] == 2) // player
					{
						printf("○");
					}
					else if (pan[i][j] == 3) // 총알
					{
						printf("★");
					}
				}
				printf("\n");
			}
			printf("x : %d y : %d point : %d \n", player_x, player_y, point); // 점수 표시

			// 총알에 맞았는지 확인
			int live = 0;
			for (int i = 0; i < 11; i++)
			{
				for (int j = 0; j < 11; j++)
				{
					if (pan[i][j] == 2) // 만약 배열에 2 == player 가 있다면
					{
						live++;
						point++; // 점수++
					}
				}
			}
			if (live == 0) // 맞았다면
			{
				break;
			}
			// 움직이기
			if (kbhit()) // 키보드가 눌렸다면, 안눌리면 실행이 아니됨
			{
				key = getch(); // 확인
				if (key == 224) // 방향키 라면
				{
					key = getch(); // 한번 더 확인
					 // 윗 방향키
					if (key == UP)
					{
						if (pan[player_x - 1][player_y] != 1) // 위에 벽이 아니라면
						{
							pan[player_x][player_y] = 0; // 공백
							player_x--; // player의 배열값이 올라감
							pan[player_x][player_y] = 2; // player
							system("cls"); // 화면초기화
						}
						else // 벽에 박을시
						{
							system("cls"); // 화면초기화
						}
					}
					// 아래 방향키
					else if (key == DOWN)
					{
						if (pan[player_x + 1][player_y] != 1) // 아래에 벽이 아니라면
						{
							pan[player_x][player_y] = 0; // 공백
							player_x++; // player의 배열값이 낮아짐
							pan[player_x][player_y] = 2; // player
							system("cls"); // 화면초기화
						}
						else // 벽에 박을시
						{
							system("cls"); //화면초기화
						}
					}
					// 왼쪽 방향키
					else if (key == LEFT)
					{
						if (pan[player_x][player_y - 1] != 1) // 왼쪽에 벽이 아니라면
						{
							pan[player_x][player_y] = 0; // 공백
							player_y--; // player의 배열값을 왼쪽으로
							pan[player_x][player_y] = 2; // player
							Sleep(100);
							system("cls"); // 화면초기화
						}
						else // 벽에 박을시
						{
							system("cls"); // 화면초기화
						}
					}
					// 오른쪽 방향키
					else if (key == RIGHT)
					{
						if (pan[player_x][player_y + 1] != 1) // 오른쪽에 벽이 아니라면
						{
							pan[player_x][player_y] = 0; // 공백
							player_y++; // player의 배열값을 오른쪽으로
							pan[player_x][player_y] = 2; // player
							system("cls"); // 화면초기화
						}
						else // 벽에 박을시
						{
							system("cls"); // 화면초기화
						}
					}
				}
			}
			// 총알이 플레이어보다 나중에 움직이므로 총알이 플레이어를 덮음
			Sleep(100); // 0.1초마다 움직이게 하기
			pan[bUX][bUY] = 0; // 총알없애기
			pan[bDX][bDY] = 0; // 총알없애기
			pan[bLX][bLY] = 0; // 총알없애기
			pan[bRX][bRY] = 0; // 총알없애기
			bUX--; // bulletU 총알 배열값이 올라감
			bDX++; // bulletD 총알 배열값이 내라감
			bLY--; // bulletL 총알 배열값이 왼쪽으로 밀려남
			bRY++; // bulletR 총알 배열값이 오른쪽으로 밀려남
			if (bUX == 0) // 위로 가는 총알이 벽에 닿았다면
			{
				bUX = 9; // 다시 가장 아래로
				bUY = rand() % 9 + 1;
			}
			if (bDX == 10) // 아래로 가는 총알이 벽에 닿았다면
			{
				bDX = 1; // 다시 가장 위로
				bDY = rand() % 9 + 1;
			}
			if (bLY == 0) // 왼쪽으로 가는 총알이 벽에 닿았다면
			{
				bLY = 9; // 다시 가장 오른쪽으로
				bLX = rand() % 9 + 1;
			}
			if (bRY == 10) // 오른쪽으로 가는 총알이 벽에 닿았다면
			{
				bRY = 1; // 다시 가장 왼쪽로
				bRX = rand() % 9 + 1;
			}
			pan[bUX][bUY] = 3; // 총알생성
			pan[bDX][bDY] = 3; // 총알생성
			pan[bLX][bLY] = 3; // 총알생성
			pan[bRX][bRY] = 3; // 총알생성
			system("cls"); // 총알움직이고 화면초기화
		}
		int restart = 0;
		printf("계속 하시려면 [1]을\n");
		printf("그만 하시려면 아무키나 입력해주세요. >> ");
		scanf("%d", &restart);
		if (restart == 1) // 그만한다면
		{
			system("cls"); // 화면초기화 
		}
		else // 다시한다면
		{
			break; // 게임 끝
		}
	}
}

