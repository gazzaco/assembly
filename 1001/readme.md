```markdown
# Chapter 4: Data Transfers, Addressing, and Arithmetic (데이터 전송, 주소 지정, 산술 연산)

## 1. 데이터 전송 명령어
* **`MOV dest, source`:** 데이터 복사 (단, **메모리 간 직접 이동 불가**, 두 피연산자 크기 일치 필수, `EIP`를 목적지로 사용 불가).
* **`MOVZX` (Zero-Extend):** 부호 없는(Unsigned) 작은 정수를 큰 레지스터로 복사하며 상위 비트를 `0`으로 채움.
* **`MOVSX` (Sign-Extend):** 부호 있는(Signed) 작은 정수를 큰 레지스터로 복사하며 상위 비트를 부호 비트로 채움.
* **`XCHG op1, op2`:** 두 피연산자의 값을 교환 (상수 불가, 최소 하나는 레지스터여야 함).

---

## 2. 산술 연산 및 CPU 상태 플래그
* **주요 명령어:** `INC` (+1), `DEC` (-1), `ADD` (덧셈), `SUB` (뺄셈), `NEG` (2의 보수 부호 반전).
  *(※ 주의: `INC`와 `DEC`는 Carry Flag에 영향을 주지 않음)*
* **상태 플래그 (Status Flags):**
  * **CF (Carry Flag):** **부호 없는(Unsigned)** 연산에서 올림/빌림 발생 시 `1` (Unsigned Overflow).
  * **OF (Overflow Flag):** **부호 있는(Signed)** 연산에서 표현 범위 초과 시 `1` (Signed Overflow).
  * **ZF (Zero Flag):** 연산 결과가 `0`이면 `1`.
  * **SF (Sign Flag):** 연산 결과의 최상위 비트(MSB)가 `1`(음수)이면 `1`.
  * **PF (Parity Flag):** 결과의 최하위 바이트에 `1`의 개수가 짝수이면 `1`.
  * **AC (Auxiliary Carry):** 비트 3에서 비트 4로 자리올림 발생 시 `1`.

---

## 3. 데이터 관련 연산자 및 지시어
* **`OFFSET`:** 세그먼트 시작점으로부터 변수의 거리(주소 오프셋) 반환.
* **`PTR`:** 피연산자의 기본 크기 속성을 강제 재정의 (예: `mov ax, WORD PTR myDword`).
* **`TYPE`:** 변수 또는 배열 단일 요소의 바이트 크기 반환 (`BYTE`=1, `WORD`=2, `DWORD`=4).
* **`LENGTHOF`:** 배열의 총 요소 개수 반환.
* **`SIZEOF`:** 배열이 차지하는 총 바이트 수 반환 (`TYPE × LENGTHOF`).
* **`ALIGN`:** 메모리 접근 속도 향상을 위해 변수를 지정된 바이트 배수 경계에 정렬.

---

## 4. 간접 주소 지정 (Indirect Addressing) 및 루프
* **간접 피연산자:** 주소를 담은 레지스터를 대괄호로 감싸 역참조 (`mov al, [esi]`).
* **인덱스 피연산자 & 스케일 팩터:** `arrayD[esi * TYPE arrayD]` 형태로 배열 요소에 직관적 접근.
* **`JMP label`:** 지정된 레이블로 무조건 분기.
* **`LOOP label`:** `ECX` 레지스터를 자동으로 1 감소시킨 후, `ECX != 0`이면 레이블로 분기.
  *(※ 중첩 루프 사용 시 외부 루프의 `ECX` 값을 별도 변수나 스택에 백업해야 함)*


---


쿠다 C (CUDA C/C++) : 엔비디아가 개발한 그래픽 처리 장치의 강력한 병렬 연산을 활용할 수 있게 해주는 확장 모델


operand


```
mov ecx, 1
sub ecs,1
mov eax, 0FFFFFFFFh
inc eax
inc eax
dec eax
```

한챕터에서 2문제정도

15문제 정도 나옴.


6장 정도까지 나갈듯

코드 문제도 손으로 적어야함
