
과제 !! -> 부모님이랑 진대하기 !!

---


# Chapter 9: 문자열과 배열 (Strings and Arrays)

Kip Irvine 어셈블리어 교재 **9장(Strings and Arrays)**의 핵심 개념과 연습문제 풀이 파일 구성을 정리한 문서입니다.

---

## 1. 파일 구성

| 파일명 | 내용 | 문항 수 |
| :--- | :--- | :---: |
| `9.9.1.txt` | 9.9절 복습 문제 한글 번역 및 정답 | 14문항 |
| `9.9.2.txt` | 9.9절 연습 문제 한글 번역 및 어셈블리 정답 | 12문항 |
| `9.10.txt` | 9.10절 프로그래밍 연습 문제 한글 번역 및 코드 구현 | 14문항 |

---

## 2. 핵심 개념 요약

### 문자열 기본 명령어 (String Primitives)
* **주요 명령어:** `MOVSB`/`MOVSW`/`MOVSD`, `CMPSB`/`CMPSW`/`CMPSD`, `SCASB`/`SCASW`/`SCASD`, `LODSB`/`LODSW`/`LODSD`, `STOSB`/`STOSW`/`STOSD`
* **인덱스 레지스터와 방향 플래그(Direction Flag, DF):**
  * `CLD` (`DF = 0`): 포인터(`ESI`, `EDI`)가 순방향(오름차순, `+1 / +2 / +4`)으로 이동합니다.
  * `STD` (`DF = 1`): 포인터(`ESI`, `EDI`)가 역방향(내림차순, `-1 / -2 / -4`)으로 이동합니다.
* **반복 접두사(Repeat Prefixes):**
  * `REP`: `ECX`가 0이 될 때까지 반복(`MOVS`, `STOS`, `LODS` 계열에 주로 사용).
  * `REPE` / `REPZ`: 같거나 Zero Flag가 설정된 동안 `ECX` 감소하며 반복(`CMPS`, `SCAS` 검색/비교에 활용).
  * `REPNE` / `REPNZ`: 다르거나 Zero Flag가 해제된 동안 `ECX` 감소하며 반복.

### 주소 지정 방식과 다차원 배열 (Addressing & 2D Arrays)
* **기저-인덱스 및 변위 주소 지정:** `[base + index + disp]` 형태로 32비트(`EBX`/`ESI`/`EDI`) 및 64비트(`RBX`/`RSI`/`RDI`) 모드에서 배열 요소를 참조합니다.
* **행-우선 순서(Row-Major Order):** 2차원 배열에서 `(행 인덱스 * 열 개수 + 열 인덱스) * 자료형 크기`로 선형 오프셋을 계산합니다.

### 문자열 프로시저와 검색·정렬 알고리즘
* **문자열 프로시저(`Str_length`, `Str_copy`, `Str_trim`, `Str_ucase`, `Str_compare` 등):** 널 종료 문자열(`0`)을 기준으로 길이를 구하거나, 후행 문자를 제거하고, 대소문자를 변환하거나, 사전순 비교를 수행합니다.
* **이진 탐색(Binary Search)과 버블 정렬(Bubble Sort):** 정렬된 배열에서 중간값(`mid`) 비교로 탐색 범위를 절반씩 줄이거나, 인접 원소 교환 및 교환 플래그(exchange flag)로 정렬을 최적화합니다.

---

## 3. 프로그래밍 연습(9.10절) 주요 구현 항목

* **문자열 조작/탐색:** `Str_copyN`, `Str_concat`, `Str_remove`, `Str_find`, `Str_nextWord`
* **문자열 트리밍 변형:** 선행 문자 제거 및 지정 문자 집합 후행 제거
* **데이터 처리 및 알고리즘:** 빈도표 생성(`Get_frequencies`), 에라토스테네스의 체(65,000 소수 탐색), 교환 플래그 적용 버블 정렬, 레지스터 기반 이진 탐색, 2차원 배열 행 합계(`calc_row_sum`), 모음 확률 조건이 있는 4x4 문자 행렬 생성 및 탐색
