ftpserver.ksecole.kr

id : assem

pwd : assem2026

인프런 - 어셈블리어 (무료강의)


결석 2번, 지각 4번 이상은 A그룹에서 제외

질문답변과 발표 위주로 진행

1. 컴퓨터란?
2. CPU?
3. Memory?
4. Debug?
5. AI시대에서 왜 Assembly를 배워야 하나?

단톡방 : ksasm

참여코드 : assm

닉네임 변경 : 학번이름(2024964049황주은)

---

https://text-to-speech.imtranslator.net/

열정학기제

KMOVE

일학습병행제



생각을 조심하라 그것이 너의 말이 된다.

말을 조심하라 그것이 너의 행동이 된다.

행동을 조심하라 그것이 너의 습관이 된다.

습관을 조심하라 그것이 너의 성격이 된다.

성격을 조심하라 그것이 너의 운명이 된다.

---
# Chapter 1: Basic Concepts (기본 개념)

## 1. 어셈블리 언어 개요
* **기계어와의 관계:** 어셈블리 언어는 CPU가 직접 이해하는 기계어(Machine Language)와 **1:1 대응** 관계를 가집니다. (고급 언어는 1:다 대응)
* **이식성 (Portability):** 특정 프로세서 아키텍처(x86, ARM 등)에 종속적이므로 이식성이 없습니다.
* **주요 활용 분야:** 임베디드 시스템, 디바이스 드라이버, 실시간 시뮬레이션, 게임 엔진 코어 최적화, 리버스 엔지니어링.
* **빌드 도구:**
  * **Assembler (MASM):** 어셈블리 소스 코드(`.asm`)를 기계어 목적 파일(`.obj`)로 번역.
  * **Linker:** 목적 파일과 라이브러리를 결합하여 실행 파일(`.exe`) 생성.
  * **Debugger:** 실행 중 레지스터와 메모리 상태를 단계별로 추적.

---

## 2. 가상 머신 개념 (Virtual Machine Concept)
컴퓨터의 하드웨어와 소프트웨어 계층 간의 추상화 관계를 설명하는 모델입니다.
* **Level 4 (High-Level Language):** C, C++, Java 등 (컴파일러를 통해 Level 3/2로 번역)
* **Level 3 (Assembly Language):** `MOV`, `ADD` 등의 니모닉 사용 (어셈블러를 통해 Level 2로 번역)
* **Level 2 (Instruction Set Architecture, ISA):** 기계어 명령어 집합 (하드웨어 직접 실행 또는 마이크로프로그램 해석)
* **Level 1 (Digital Logic):** 실제 물리적 디지털 논리 회로

---

## 3. 데이터 표현 (Data Representation)
* **진법 변환:** 2진수(Binary), 10진수(Decimal), 16진수(Hexadecimal, 4비트당 1자리).
* **저장 단위:**
  * `Byte`: 8 bits
  * `Word`: 16 bits (2 bytes)
  * `Doubleword (DWORD)`: 32 bits (4 bytes)
  * `Quadword (QWORD)`: 64 bits (8 bytes)
* **음수 표현 (2의 보수, Two's Complement):**
  * 최상위 비트(MSB)가 `0`이면 양수, `1`이면 음수.
  * 변환 방법: 모든 비트를 반전(1의 보수)한 뒤 `1`을 더함.
* **문자 인코딩:**
  * **ASCII:** 7비트 표준 문자 집합 (1바이트 저장).
  * **Unicode:** 전 세계 문자 표현 (UTF-8, UTF-16, UTF-32).

---

## 4. 불 대수 (Boolean Expressions)
* **기본 연산자 우선순위:** `NOT` ($\neg$) $\rightarrow$ `AND` ($\wedge$) $\rightarrow$ `OR` ($\vee$)
* **드 모르간의 법칙:** $\neg(A \vee B) = \neg A \wedge \neg B$, $\quad \neg(A \wedge B) = \neg A \vee \neg B$
