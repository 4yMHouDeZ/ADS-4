// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  while (arr[len-1] > value && len >= 0) {
    len--;
  }
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}

// бинарный поиск индекса заданного числа value в массиве arr
int findDigit(int *arr, int lbound, int rbound, int value) {
  int index = lbound + (rbound - lbound) / 2;
  if (value == arr[index]) return index;
  if (rbound == lbound) return -1;
  else if (value > arr[index]) return findDigit(arr, index + 1, rbound, value);
  else return findDigit(arr, lbound, index - 1, value);
}

// лин поиск кол-ва value начинающийся с индекса, найденного findDigit()
int countDigit(int *arr, int len, int value) {
  int count = 1;
  int index = findDigit(arr, 0, len, value);
  if (index == -1) return 0;
  int i = index - 1;
  while (i >= 0 && arr[i] == value) {
    count++;
    i--;
  }
  i = index + 1;
  while (i < len && arr[i] == value) {
    count++;
    i++;
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  // убираем лишние
  while (arr[len-1] > value && len > 0) {
    len--;
  }

  int n = 0;
  // цикл до половины от value
  while (arr[n] < value / 2) {
    count += countDigit(arr, len, value - arr[n]);
    n++;
  }
  // добавляем пары с половинами от value
  if (value % 2 == 0) {
    int temp = countDigit(arr, len, value / 2);
    for (int i = temp - 1; i > 0; i--) {
      count += i;
    }
  }
  return count;
}
