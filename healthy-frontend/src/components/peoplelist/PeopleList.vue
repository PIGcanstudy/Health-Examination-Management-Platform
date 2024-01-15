<template>
  <!-- 列表名称区域 -->
  <el-card class="top">
    <div class="list-name">
      <span>人员列表</span>
    </div>
  </el-card>

  <!-- 主体部分 -->
  <el-card class="body" shadow="hover">
    <!-- 表单空间区域 -->
    <div class="form-area">
      <el-form ref="ruleFormRef" :model="ruleForm" :rules="rules" class="demo-ruleForm" :size="formSize">
        <el-form-item prop="resource">
          <el-radio-group v-model="form.resource" class="resource">
            <el-radio label="已检" />
            <el-radio label="未检" />
          </el-radio-group>
          <el-switch width="60" v-model="form.delivery" inline-prompt active-text="复查" inactive-text="非复"></el-switch>
        </el-form-item>
        <el-form-item prop="time-picker">
          <el-row clearable>
            <el-date-picker v-model="form.startDate" type="date" placeholder="开始时间" width="100" />
          </el-row>
          <el-row>
            <span>~</span>
          </el-row>
          <el-row clearable>
            <el-date-picker v-model="form.endDate" type="date" placeholder="结束时间" width="100%" />
          </el-row>
        </el-form-item>
        <el-form-item prop="search1">
          <el-input v-model="form.name" placeholder="请输入姓名" clearable />
        </el-form-item>
        <el-form-item prop="search2">
          <el-input v-model="form.serialNumber" placeholder="请输入体检编号" clearable />
        </el-form-item>
        <el-form-item prop="search3">
          <el-input v-model="form.workplace" placeholder="请输入单位名称" clearable />
        </el-form-item>

        <el-form-item prop="function-button">
          <el-button type="primary" @click="onSubmit">查询</el-button>
          <el-button plain @click="resetForm">重置</el-button>
          <el-button type="text"
            >展开<el-icon><ArrowDown /></el-icon>
          </el-button>
        </el-form-item>
      </el-form>
    </div>

    <!-- 表格数据区域 -->
    <div class="table-area">
      <el-table ref="multipleTableRef" :data="tableData" style="width: 100%" @row-click="rowClickHandle" v-loading="loading" highlight-current-row :show-header="false" fit>
        <el-table-column type="selection" width="50" />
        <el-table-column property="name1">
          <!-- <template>{{ scope.row.name }}</template> -->
        </el-table-column>
        <el-table-column property="gender">
          <!-- <template>{{ scope.row.gender }}</template> -->
        </el-table-column>
        <el-table-column property="age">
          <!-- <template>{{ scope.row.age }}</template> -->
        </el-table-column>
        <el-table-column property="tags">
          <el-tag class="tag2" type="success">健</el-tag>
          <el-tag class="tag2" type="danger">零</el-tag>
        </el-table-column>
      </el-table>
    </div>

    <!-- 分页区域 -->
    <el-pagination
      v-model:current-page="currentPage"
      v-model:page-size="pageSize"
      layout="prev, jumper, pager, next, "
      :total="50"
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
    />
  </el-card>
</template>

<script setup>
import { ref } from 'vue'
import { ArrowDown } from '@element-plus/icons-vue'

// 表格数据存放区域
const multipleTableRef = ref()
const tableData = [
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '健'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  }
]

// 分页逻辑
const currentPage = ref(1)
const pageSize = ref(10)
const handleSizeChange = () => {}
const handleCurrentChange = () => {}
</script>

<style lang="scss" scoped></style>
