/*
 Navicat Premium Dump SQL

 Source Server         : sql_test1
 Source Server Type    : MySQL
 Source Server Version : 80040 (8.0.40)
 Source Host           : localhost:3306
 Source Schema         : sql_test

 Target Server Type    : MySQL
 Target Server Version : 80040 (8.0.40)
 File Encoding         : 65001

 Date: 18/12/2024 00:26:00
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for bill
-- ----------------------------
DROP TABLE IF EXISTS `bill`;
CREATE TABLE `bill`  (
  `Bill_ID` bigint NOT NULL AUTO_INCREMENT,
  `Begin_Time` datetime NULL DEFAULT NULL,
  `End_Time` datetime NULL DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP,
  `Cost` int NULL DEFAULT NULL,
  `Car_Card` varchar(20) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `State` tinyint(1) NULL DEFAULT NULL,
  `Park_Index` int NULL DEFAULT 0,
  PRIMARY KEY (`Bill_ID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 9999708790 CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of bill
-- ----------------------------
INSERT INTO `bill` VALUES (1, '2024-12-05 19:43:30', '2024-12-17 17:14:37', 90, 'nb666', 1, 9);
INSERT INTO `bill` VALUES (9999708751, '2024-12-12 17:07:36', '2024-12-17 18:30:09', 0, 'qaz', 0, 2);
INSERT INTO `bill` VALUES (9999708757, '2024-12-14 17:38:59', '2024-12-17 18:30:13', 0, 'zxc', 0, 3);
INSERT INTO `bill` VALUES (9999708758, '2024-12-16 17:39:38', '2024-12-17 18:30:17', 0, 'sb123', 0, 4);
INSERT INTO `bill` VALUES (9999708759, '2024-12-01 17:47:31', '2024-12-17 23:21:21', 160, 'a1', 1, 5);
INSERT INTO `bill` VALUES (9999708760, '2024-12-04 17:47:43', '2024-12-17 23:42:23', 130, 'a2', 1, 6);
INSERT INTO `bill` VALUES (9999708761, '2024-12-17 17:47:51', '2024-12-17 17:47:51', 0, 'a3', 0, 7);
INSERT INTO `bill` VALUES (9999708762, '2024-12-17 17:48:09', '2024-12-17 17:48:09', 0, 'a4', 0, 8);
INSERT INTO `bill` VALUES (9999708763, '2024-12-10 17:49:14', '2024-12-17 18:47:20', 70, 'a5', 1, 1);
INSERT INTO `bill` VALUES (9999708764, '2024-12-05 17:49:19', '2024-12-17 18:42:02', 120, 'a6', 1, 10);
INSERT INTO `bill` VALUES (9999708769, '2024-12-17 18:12:52', '2024-12-17 22:38:45', 0, 'abcdefg', 1, 0);
INSERT INTO `bill` VALUES (9999708771, '2024-12-17 22:38:14', '2024-12-17 23:19:07', 0, 'a5', 1, 1);
INSERT INTO `bill` VALUES (9999708772, '2024-12-17 22:38:32', '2024-12-17 22:38:45', 0, 'abcdefg', 1, 10);
INSERT INTO `bill` VALUES (9999708773, '2024-12-17 22:39:09', '2024-12-17 22:39:09', 0, 'abcdefg', 0, 10);
INSERT INTO `bill` VALUES (9999708783, '2024-12-17 23:16:55', '2024-12-17 23:18:54', 0, 'a6', 1, 0);
INSERT INTO `bill` VALUES (9999708784, '2024-12-17 23:19:52', '2024-12-17 23:25:42', 0, 'a6', 1, 1);
INSERT INTO `bill` VALUES (9999708785, '2024-12-17 23:24:51', '2024-12-17 23:24:51', 0, 'a1', 0, 5);
INSERT INTO `bill` VALUES (9999708786, '2024-12-17 23:25:16', '2024-12-17 23:25:42', 0, 'a6', 1, 1);
INSERT INTO `bill` VALUES (9999708787, '2024-12-17 23:25:48', '2024-12-17 23:26:07', 0, 'a5', 1, 1);
INSERT INTO `bill` VALUES (9999708788, '2024-12-17 23:41:32', '2024-12-17 23:41:32', 0, 'a6', 0, 1);
INSERT INTO `bill` VALUES (9999708789, '2024-12-17 23:41:56', '2024-12-17 23:41:56', 0, 'a5', 0, 0);

-- ----------------------------
-- Table structure for car
-- ----------------------------
DROP TABLE IF EXISTS `car`;
CREATE TABLE `car`  (
  `Car_Card` varchar(20) CHARACTER SET gbk COLLATE gbk_chinese_ci NOT NULL,
  `Car_Owner_Name` varchar(20) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `Car_Owner_ID` int NULL DEFAULT NULL,
  PRIMARY KEY (`Car_Card`) USING BTREE,
  INDEX `约束`(`Car_Owner_ID` ASC) USING BTREE,
  CONSTRAINT `约束` FOREIGN KEY (`Car_Owner_ID`) REFERENCES `user` (`User_ID`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of car
-- ----------------------------
INSERT INTO `car` VALUES ('a1', 't2', 10006);
INSERT INTO `car` VALUES ('a2', 't2', 10006);
INSERT INTO `car` VALUES ('a3', 't3', 10007);
INSERT INTO `car` VALUES ('a4', 't4', 10008);
INSERT INTO `car` VALUES ('a5', 'a5', 10009);
INSERT INTO `car` VALUES ('a6', 'a6', 10010);
INSERT INTO `car` VALUES ('a7', 'a7', 10011);
INSERT INTO `car` VALUES ('abcdefg', 'djh', 10003);
INSERT INTO `car` VALUES ('hlysb', 'hly', 10004);
INSERT INTO `car` VALUES ('nb666', 'ljj', 3);
INSERT INTO `car` VALUES ('qaz', 'hyq', 10002);
INSERT INTO `car` VALUES ('sb123', 'ybk', 5);
INSERT INTO `car` VALUES ('zxc', 'ybk', 5);

-- ----------------------------
-- Table structure for parking
-- ----------------------------
DROP TABLE IF EXISTS `parking`;
CREATE TABLE `parking`  (
  `Park_Index` int NOT NULL,
  `Cur_Car_Card` varchar(25) CHARACTER SET gbk COLLATE gbk_chinese_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`Park_Index`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of parking
-- ----------------------------
INSERT INTO `parking` VALUES (1, 'a6');
INSERT INTO `parking` VALUES (2, 'qaz');
INSERT INTO `parking` VALUES (3, 'zxc');
INSERT INTO `parking` VALUES (4, 'sb123');
INSERT INTO `parking` VALUES (5, 'a1');
INSERT INTO `parking` VALUES (6, '');
INSERT INTO `parking` VALUES (7, 'a3');
INSERT INTO `parking` VALUES (8, 'a4');
INSERT INTO `parking` VALUES (9, 'nb666');
INSERT INTO `parking` VALUES (10, 'abcdefg');

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`  (
  `User_ID` int NOT NULL AUTO_INCREMENT,
  `User_Name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `User_Sex` varchar(5) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`User_ID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 10013 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES (2, 'sbdj', 'man');
INSERT INTO `user` VALUES (3, 'ljj', 'man');
INSERT INTO `user` VALUES (4, 'dh', 'woman');
INSERT INTO `user` VALUES (5, 'ybk', 'woman');
INSERT INTO `user` VALUES (6, 'dj', 'woman');
INSERT INTO `user` VALUES (10001, 'zhangyifei', 'woman');
INSERT INTO `user` VALUES (10002, 'hyq', 'woman');
INSERT INTO `user` VALUES (10003, 'djh', 'woman');
INSERT INTO `user` VALUES (10004, 'hly', 'woman');
INSERT INTO `user` VALUES (10005, 'test', 'man');
INSERT INTO `user` VALUES (10006, 't2', 'man');
INSERT INTO `user` VALUES (10007, 't3', 'man');
INSERT INTO `user` VALUES (10008, 't4', 'man');
INSERT INTO `user` VALUES (10009, 'a5', 'man');
INSERT INTO `user` VALUES (10010, 'a6', 'man');
INSERT INTO `user` VALUES (10011, 'a7', 'man');

-- ----------------------------
-- Procedure structure for AssignParking
-- ----------------------------
DROP PROCEDURE IF EXISTS `AssignParking`;
delimiter ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `AssignParking`(IN carin VARCHAR(255))
BEGIN
    DECLARE available_park_index INT;

    -- 开始事务
    START TRANSACTION;

    -- 查找可用的车位
    SELECT Park_Index INTO available_park_index
    FROM `Parking`
    WHERE Cur_Car_Owner_ID = 0
    LIMIT 1;

    -- 检查车位是否可用
    IF available_park_index IS NOT NULL THEN
        -- 插入新订单
        INSERT INTO `Bill` (Begin_Time, End_Time, Cost, Car_Card, State, Park_Index)
        VALUES (NOW(), NULL, 0, carin, 0, available_park_index);
        
--         update `parking`
--         SET Cur_Car_Owner_ID=(select Car_Owner_ID FROM `Car` where Car_Card=carin)
--         WHERE Park_Index=available_park_index;
        UPDATE `Parking` p
        JOIN `Car` c ON c.Car_Card = carin
        SET p.Cur_Car_Owner_ID = c.Car_Owner_ID
        WHERE p.Park_Index = available_park_index;
    ELSE
        -- 处理没有可用车位的情况
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'No available parking space';
    END IF;

    -- 提交事务
    ROLLBACK;
END
;;
delimiter ;

-- ----------------------------
-- Triggers structure for table car
-- ----------------------------
DROP TRIGGER IF EXISTS `before_insert_car`;
delimiter ;;
CREATE TRIGGER `before_insert_car` BEFORE INSERT ON `car` FOR EACH ROW BEGIN
    DECLARE user_count INT;

    -- 检查 User 表中是否存在对应的 User_Name 和 User_ID
    SELECT COUNT(*)
    INTO user_count
    FROM `User`
    WHERE User_Name = NEW.Car_Owner_Name AND User_ID = NEW.Car_Owner_ID;

    -- 如果没有找到对应的记录，则抛出错误
    IF user_count = 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'No matching User_Name and User_ID found in User table.';
    END IF;
END
;;
delimiter ;

-- ----------------------------
-- Triggers structure for table car
-- ----------------------------
DROP TRIGGER IF EXISTS `before_update_car`;
delimiter ;;
CREATE TRIGGER `before_update_car` BEFORE UPDATE ON `car` FOR EACH ROW BEGIN
    DECLARE user_count INT;

    -- 检查 User 表中是否存在对应的 User_Name 和 User_ID
    SELECT COUNT(*)
    INTO user_count
    FROM `User`
    WHERE User_Name = NEW.Car_Owner_Name AND User_ID = NEW.Car_Owner_ID;

    -- 如果没有找到对应的记录，则抛出错误
    IF user_count = 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'No matching User_Name and User_ID found in User table.';
    END IF;
END
;;
delimiter ;

-- ----------------------------
-- Triggers structure for table user
-- ----------------------------
DROP TRIGGER IF EXISTS `update_car_owner_Name`;
delimiter ;;
CREATE TRIGGER `update_car_owner_Name` AFTER UPDATE ON `user` FOR EACH ROW BEGIN
    IF OLD.User_Name <> NEW.User_Name THEN
        UPDATE `Car`
        SET Car_Owner_Name = NEW.User_Name
        WHERE Car_Owner_Name = OLD.User_Name AND Car_Owner_ID = NEW.User_ID;  -- 使用 NEW.User_ID
    END IF;
END
;;
delimiter ;

SET FOREIGN_KEY_CHECKS = 1;
