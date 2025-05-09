## 기능 3 - 파일 사이즈 비교

- 파일 이름: `text1`, `text2`
- 비교 대상: 두 파일의 `st_size` (파일 크기)
- 결과 출력:
  - text1이 더 크면: `text1 is bigger`
  - text2가 더 크면: `text2 is bigger`
  - 같으면: `sizes are equal`
- 관련 함수: `sizecmp()`
- 관련 시스템 콜: `stat()`
- 예시 출력:
