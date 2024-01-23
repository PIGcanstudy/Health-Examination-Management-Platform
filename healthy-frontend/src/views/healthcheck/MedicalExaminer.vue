<!--
 * @Author: setti5 2283356040@qq.com
 * @Date: 2024-01-22 18:16:25
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2024-01-22 21:09:45
 * @FilePath: \zero-one-healthy-check\healthy-frontend\src\views\healthcheck\MedicalExaminer.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<!-- 体检人员 -->
<template>
  <el-container style="height: 100%">
    <el-aside>
      <!-- 还没改名字：团检订单 -->
      <PeopleList style="height: 100%; width: 100%" />
    </el-aside>
    <el-main style="display: flex">
      <!-- 中间部分：团检人员 -->
      <div class="center-part" shadow="false">
        <el-card style="background-color: rgb(240, 250, 255)">
          <el-row style="align-items: center; justify-content: center; border: 1px solid #fff">
            <div class="title" style="margin-right: 10px">团检人员</div>
            <el-button type="primary">
              <el-icon><Upload /></el-icon>
              导入
            </el-button>
            <el-button type="primary">
              <el-icon><CirclePlus /></el-icon> 新增
            </el-button>
            <el-button type="primary">
              <el-icon><Download /></el-icon>
              导出
            </el-button>
            <el-button type="primary">
              <el-icon><Download /></el-icon>
              导出订单
            </el-button>
          </el-row>
        </el-card>
        <el-card>
          <PersonInfo :person-info="tableData" style="margin-bottom: 15px" />
          <el-pagination></el-pagination>
        </el-card>
      </div>
      <!-- 右边部分：订单信息 -->
      <div class="right-part" style="margin-left: 4px; align-items: center; justify-content: center" shadow="false">
        <div class="head" style="align-items: center">
          <el-card style="background-color: rgb(240, 250, 255)"> 订单信息 </el-card>
          <el-card>content</el-card>
        </div>
        <div class="body" style="margin-top: 4px">
          <el-card style="background-color: rgb(240, 250, 255)">团体项目</el-card>
          <el-card>content</el-card>
        </div>
      </div>
    </el-main>
  </el-container>
</template>

<script setup>
import PeopleList from '@/components/peoplelist/PeopleList.vue'
import { Upload, CirclePlus, Download } from '@element-plus/icons-vue'
</script>

<style lang="scss" scoped>
.center-part {
  height: 100%;
}
</style>
