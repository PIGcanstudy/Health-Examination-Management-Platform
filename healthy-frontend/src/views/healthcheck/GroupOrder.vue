<!-- 团检订单 -->
<template>
  <el-container style="height: 100%">
    <el-aside width="250px">
      <PeopleList style="height: 100%; width: 100%" />
    </el-aside>
    <el-main style="">
      <!-- 按钮 -->
      <el-row style="margin-bottom: 15px">
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
      </el-row>

      <!-- 表单 -->
      <el-form :inline="true" :model="formInline" class="demo-form-inline" style="padding: 0 25px">
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
      </el-form>

      <!-- 体检项目 -->
      <div class="alter" style="display: flex; padding-bottom: 5px">
        <span>体检项目</span>
        <el-button type="primary" size="small">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary" size="small">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
      </div>
      <PersonInfo :personInfo="tableData" style="margin-bottom: 15px" />

      <!-- 体检人员 -->
      <div class="alter" title="success alert">
        <span>体检人员</span>
      </div>
      <Details :details="tableData"></Details>
    </el-main>
  </el-container>
</template>

<script setup></script>

<style lang="scss" scoped></style>
