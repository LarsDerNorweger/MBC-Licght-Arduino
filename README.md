# MBC LIGHT Controller

# Protocoll

The communication is driven by SerialPort.

## The Protocoll

style by csv

$PIN,$ENABLED,$CHANGETIME,$GROUP

| PIN  | ENABLED | CHANGETIME | GROUP | ACTION             |
| ---- | ------- | ---------- | ----- | ------------------ |
| NULL | NULL    | 0          | 0     | addGroup           |
| 0    | NULL    | NULL       | 0     | addPinToGroup      |
| 0    | 1       | NULL       | 0     | addPinAsLeader     |
| 0    | 0/1     | 0-1000     | NULL  | addPInWithoutGroup |
